#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "calc_frames.h"

frame_t test_vector[][NFRAMES] = {
    {{10, 0, 0, 30}, {10, 0, 0, 60}, {10, 0, 0, 90}, {10, 0, 0, 120}, {10, 0, 0, 150}, {10, 0, 0, 180}, {10, 0, 0, 210}, {10, 0, 0, 240}, {10, 0, 0, 270}, {10, 10, 10, 300}},
    {{5, 5, 0, 15}, {5, 5, 0, 30}, {5, 5, 0, 45}, {5, 5, 0, 60}, {5, 5, 0, 75}, {5, 5, 0, 90}, {5, 5, 0, 105}, {5, 5, 0, 120}, {5, 5, 0, 135}, {5, 5, 5, 150}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 2, 0, 3}, {5, 5, 0, 23}, {10, 0, 0, 41}, {5, 3, 0, 49}, {5, 5, 0, 69}, {10, 0, 0, 86}, {2, 5, 0, 93}, {10, 0, 0, 113}, {5, 5, 0, 126}, {3, 2, 0, 131}},
    {{9, 0, 0, 9}, {5, 5, 0, 29}, {10, 0, 0, 47}, {8, 0, 0, 55}, {5, 5, 0, 75}, {10, 0, 0, 94}, {9, 0, 0, 103}, {10, 0, 0, 123}, {5, 5, 0, 143}, {10, 7, 2, 162}},
    {{1, 1, 0, 2}, {2, 2, 0, 6}, {3, 3, 0, 12}, {4, 4, 0, 20}, {5, 5, 0, 40}, {10, 0, 0, 70}, {10, 0, 0, 100}, {10, 0, 0, 130}, {10, 0, 0, 159}, {10, 9, 1, 179}},
    {{7, 2, 0, 9}, {5, 5, 0, 29}, {10, 0, 0, 48}, {6, 3, 0, 57}, {5, 5, 0, 77}, {10, 0, 0, 96}, {8, 1, 0, 105}, {10, 0, 0, 125}, {5, 5, 0, 145}, {10, 10, 10, 175}},
};

#define NVECTORS (sizeof(test_vector) / (NFRAMES * sizeof(frame_t)))

int test_calc_frames(frame_t *frames, int frames_length)
{
  int result = 0;
  frame_t frames_without_total[frames_length]; /* VLA */

  /* fill new table in without total */
  for (int i = 0; i < frames_length; i++)
  {
    frames_without_total[i] = frames[i];
    frames_without_total[i].total = 0;
  }

  /* go through the table to calculate total*/
  for (int i = 0; i < frames_length; i++)
  {
    calc_frame_table(frames_without_total, frames_length, i);
  }

  /* compare original values vs calculated */
  for (int i = 0; i < frames_length; i++)
  {
    result = !(frames[i].total == frames_without_total[i].total);
    printf("%d: %3d vs %3d : %s\n", i, frames[i].total, frames_without_total[i].total, result ? "FAIL" : "PASS");
  }

  return result;
}

int main(void)
{
  int result = 0;
  for (int i = 0; i < NVECTORS; i++)
  {
    printf("VECTOR #%d\n", i);
    result += test_calc_frames(test_vector[i], NFRAMES);
  }

  printf("All cases passed: %s\n", result ? "FAIL" : "PASS");

  return 0;
}
