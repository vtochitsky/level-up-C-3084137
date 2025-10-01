#include "calc_scr.h"

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
      frames[f].total = frames[f].first + previous_total;
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
      frames[f].total = frames[f].first + previous_total + frames[f].second;
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
        second_roll = frames[f + 1].second;
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
