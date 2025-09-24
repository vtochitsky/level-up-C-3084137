#include "calc_frames.h"

#if defined(VER1) && !defined(VER2)

/* 'i' is current frame number */
void calc_frame_table(frame_t *frames, int frames_length, int i)
{
  /* flags */
  static int add1st = 0; // can be moved to some structure
  static int add2nd = 0; // can be moved to some structure

  /*
  --------------------------------------
  1st roll
  --------------------------------------
  */

  /* handling previous frame */
  if (1 == add1st) /* it can be true only for i > 0 */
  {
    frames[i - 1].total += frames[i].first;
    add1st = 0; // add1st--;
  }

  /* considering current frame to take it into account in a next frame */
  if (strike(frames[i]) || spare(frames[i]))
  {
    add1st = 1; // add1st++;
  }

  /*
  --------------------------------------
  2nd roll
  --------------------------------------
  */

  /* handling previous frames */
  if (2 == add2nd)
  {
    frames[i - 2].total += frames[i].first;
    frames[i - 1].total += frames[i].first;
    add2nd = 1; // add2nd--;
  }

  if (1 == add2nd && !strike(frames[i]) || 1 == add2nd && (10 - 1) == i /* add-on for frame #9 */)
  {
    frames[i - 1].total += frames[i].second;
    add2nd = 0; // add2nd--;
  }

  /* considering current frame to take it into account in next two frames (either i+1 or i+2) */
  if (strike(frames[i]))
  {
    add2nd++; // 0--->1 or 1--->2
  }

  /* only frame #10 */
  if ((10 - 1) == i)
  {
    /* strike or spare */
    if (10 == frames[i].first || 10 == (frames[i].first + frames[i].second))
    {
      frames[i].total += frames[i].third;
    }
    // finally
    add1st = add2nd = 0;
  }

  /* .total calculation for current frame  */
  int previous_total = i > 0 ? frames[i - 1].total : 0; /* previous_total is zero for the 1st frame */
  frames[i].total += frames[i].first + frames[i].second + previous_total;
}

#elif !defined(VER1) && defined(VER2)

/* states of frame */
enum
{
  NOEXEC = 0,
  FIRST,
  SPARE,
  STRIKE1,
  STRIKE2,
  DONE
};

void calc_frame_table(frame_t *frames, int frames_length /* not needed */, int i)
{
  int previous_total = 0;
  int second_roll = 0;

  int start_i = 1 < i ? i - 2 : 0;
  for (int f = start_i; f <= i; f++)
  {
    previous_total = f == 0 ? 0 : frames[f - 1].total;
    switch (frames[f].state)
    {
    case (NOEXEC):
      frames[f].total = frames[f].first + previous_total;
      if (10 == frames[f].total)
      {
        frames[f].state = STRIKE1;
      }
      else
      {
        frames[f].state = FIRST;
      }
      break;
    case (FIRST):
      frames[f].total += frames[f].second;
      if (10 == frames[f].total)
      {
        frames[f].state = SPARE;
      }
      else
      {
        frames[f].total += frames[f].third;
        frames[f].state = DONE;
      }
      break;
    case (SPARE):
      frames[f].total += frames[f + 1].first; // f+1 !!!
      frames[f].total += frames[f].third;
      frames[f].state = DONE;
      break;
    case (STRIKE1):
      frames[f].total += frames[f + 1].first; // f+1 !!!
      frames[f].state = STRIKE2;
      break;
    case (STRIKE2):
      if (STRIKE1 == frames[f + 1].state)
      {
        second_roll = frames[f + 2].first;
      }
      else
      {
        second_roll = frames[f + 1].first;
      }
      frames[f].total += second_roll;
      frames[f].total += frames[f].third;
      frames[f].state = DONE;
      break;
    case (DONE):
      break;
    default:
      break;
    }
  }
}

#else
#error "calc_frame_table implementation is not defined"
#endif