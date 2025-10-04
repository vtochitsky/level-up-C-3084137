#include "calc_scr.h"

/*
Calculates the score for a bowling game for the given frame index `i`.
It should be called each time a roll is made to update the scores accordingly!
Args:
  frames: An array of frame_t structures representing the frames of the game.
  i: The index of the current frame (0-based).
*/
void calc_score(frame_t *frames, int i)
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
      frames[f].total = previous_total + frames[f].first;
      if (10 == frames[f].first)
      {
        frames[f].state = STRIKE1;
      }
      else
      {
        frames[f].state = FIRST;
      }
      break;
    case (FIRST):
      frames[f].total = previous_total + frames[f].first + frames[f].second;
      if (10 == (frames[f].first + frames[f].second))
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
      if (f == 9) // the last frame
      {
        frames[f].total = previous_total + frames[f].first + frames[f].second + frames[f].third;
        frames[f].state = DONE;
        break;
      }
      frames[f].total += frames[f + 1].first; // f+1 !!!
      frames[f].total += frames[f].third;
      frames[f].state = DONE;
      break;
    case (STRIKE1):
      if (f == 9) // the last frame
      {
        frames[f].total = previous_total + frames[f].first + frames[f].second;
        frames[f].state = STRIKE2;
        break;
      }
      frames[f].total = previous_total + frames[f].first + frames[f + 1].first; // f+1 !!! NOT FOR the last frame
      frames[f].state = STRIKE2;
      break;
    case (STRIKE2):
      if (f == 9) // the last frame
      {
        frames[f].total = previous_total + frames[f].first + frames[f].second + frames[f].third;
        frames[f].state = DONE;
        break;
      }
      if (STRIKE1 == frames[f + 1].state)
      {
        if (f + 1 == 9) // the last frame
        {
          second_roll = frames[f + 1].second; 
        }
        else
        {
          second_roll = frames[f + 2].first;
        }
      }
      else
      {
        second_roll = frames[f + 1].second;
      }
      frames[f].total = frames[f].total + second_roll;
      frames[f].total += frames[f].third; // FOR the last frame 10 ...
      frames[f].state = DONE;
      break;
    case (DONE):
      break;
    default:
      break;
    }
  }
}
