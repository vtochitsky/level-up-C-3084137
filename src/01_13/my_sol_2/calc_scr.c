#include "calc_scr.h"

/*
 * Helper: return previous total for frame index f (0 if first frame)
 */
static int prev_total(const frame_t *frames, int f)
{
  return (f <= 0) ? 0 : frames[f - 1].total;
}

/*
 * Helper: safe accessor for next frame's first roll. Returns 0 if out of range.
 */
static int next_first(const frame_t *frames, int f, int last_index)
{
  return (f + 1 <= last_index) ? frames[f + 1].first : 0;
}

/*
 * Helper: safe accessor for following-first-in-case-of-consecutive-strikes.
 * If next frame is strike and there is one more frame, return that frame's first.
 * Otherwise return next frame's second roll (or 0 if unavailable).
 */
static int second_for_strike(const frame_t *frames, int f, int last_index)
{
  if (f + 1 > last_index)
    return 0;
  if (frames[f + 1].state == STRIKE1)
  {
    /* if next is the last frame, its "second" contains the bonus roll */
    if (f + 1 == last_index)
      return frames[f + 1].second;
    /* otherwise look one more frame ahead */
    return frames[f + 2].first;
  }
  /* next frame is not a strike: use its second roll value */
  return frames[f + 1].second;
}

/*
Calculates (or updates) the cumulative score for frames up to index i.
Call this after a roll is recorded to recompute affected frames.
*/
void calc_score(frame_t *frames, int i)
{
  if (!frames || i < 0)
    return;

  const int last_frame = 9; /* zero-based index for 10th frame */

  /* only frames that can be affected are i and up to two frames before it */
  int start = (i - 2) > 0 ? (i - 2) : 0;

  for (int f = start; f <= i; ++f)
  {
    int previous_total = prev_total(frames, f);

    switch (frames[f].state)
    {
    case NOEXEC:
      frames[f].total = previous_total + frames[f].first;
      frames[f].state = (frames[f].first == 10) ? STRIKE1 : FIRST;
      break;

    case FIRST:
      frames[f].total = previous_total + frames[f].first + frames[f].second;
      if ((frames[f].first + frames[f].second) == 10)
      {
        frames[f].state = SPARE;
      }
      else
      {
        /* open frame: include third only if present (usually zero) */
        frames[f].total += frames[f].third;
        frames[f].state = DONE;
      }
      break;

    case SPARE:
      if (f == last_frame)
      {
        /* 10th frame: all rolls already stored in frame */
        frames[f].total = previous_total + frames[f].first + frames[f].second + frames[f].third;
      }
      else
      {
        /* spare: add next frame's first roll as bonus */
        frames[f].total = previous_total + frames[f].first + frames[f].second + next_first(frames, f, last_frame);
      }
      frames[f].state = DONE;
      break;

    case STRIKE1:
      if (f == last_frame)
      {
        /* strike in last frame: total includes first two rolls so far */
        frames[f].total = previous_total + frames[f].first + frames[f].second;
        frames[f].state = STRIKE2;
      }
      else
      {
        /* base strike total: next frame's first roll is the first bonus */
        frames[f].total = previous_total + frames[f].first + next_first(frames, f, last_frame);
        frames[f].state = STRIKE2;
      }
      break;

    case STRIKE2:
      if (f == last_frame)
      {
        /* final frame: include all three rolls */
        frames[f].total = previous_total + frames[f].first + frames[f].second + frames[f].third;
      }
      else
      {
        /* complete strike bonus: need the second bonus roll after the strike */
        int second_roll = second_for_strike(frames, f, last_frame);
        frames[f].total = previous_total + frames[f].first + next_first(frames, f, last_frame) + second_roll;
        /* include third if any (usually zero for non-10th frames) */
        frames[f].total += frames[f].third;
      }
      frames[f].state = DONE;
      break;

    case DONE:
    default:
      /* nothing to do */
      break;
    }
  }
}
