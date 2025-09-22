#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "calc_frames.h"

#define NVECTORS 7

frame_t test_vector[NVECTORS][NFRAMES] = {
    {{10, 0, 0, 30}, {10, 0, 0, 60}, {10, 0, 0, 90}, {10, 0, 0, 120}, {10, 0, 0, 150}, {10, 0, 0, 180}, {10, 0, 0, 210}, {10, 0, 0, 240}, {10, 0, 0, 270}, {10, 10, 10, 300}},
    {{5, 5, 0, 15}, {5, 5, 0, 30}, {5, 5, 0, 45}, {5, 5, 0, 60}, {5, 5, 0, 75}, {5, 5, 0, 90}, {5, 5, 0, 105}, {5, 5, 0, 120}, {5, 5, 0, 135}, {5, 5, 5, 150}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 2, 0, 3}, {5, 5, 0, 18}, {10, 0, 0, 38}, {5, 3, 0, 46}, {5, 5, 0, 66}, {10, 0, 0, 86}, {2, 5, 0, 93}, {10, 0, 0, 113}, {5, 5, 0, 123}, {3, 2, 0, 128}},
    {{9, 0, 0, 9}, {5, 5, 0, 29}, {10, 0, 0, 49}, {8, 0, 0, 57}, {5, 5, 0, 77}, {10, 0, 0, 97}, {9, 0, 0, 106}, {10, 0, 0, 126}, {5, 5, 0, 136}, {10, 7, 2, 155}},
    {{1, 1, 0, 2}, {2, 2, 0, 6}, {3, 3, 0, 12}, {4, 4, 0, 20}, {5, 5, 0, 30}, {10, 0, 0, 50}, {10, 0, 0, 70}, {10, 0, 0, 100}, {10, 0, 0, 130}, {10, 9, 1, 150}},
    {{7, 2, 0, 9}, {5, 5, 0, 29}, {10, 0, 0, 49}, {6, 3, 0, 58}, {5, 5, 0, 78}, {10, 0, 0, 98}, {8, 1, 0, 107}, {10, 0, 0, 127}, {5, 5, 0, 147}, {10, 10, 10, 177}},
};

int test_calc_frames(frame_t *frames, int frames_length)
{
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
    printf("%d: %3d vs %3d : %s\n", i, frames[i].total, frames_without_total[i].total, frames[i].total == frames_without_total[i].total ? "PASS" : "FAIL");
    // assert(frames[i].total == frames_without_total[i].total);
  }

  return 0;
}

int main(void)
{

  for (int i = 0; i < NVECTORS; i++)
  {
    printf("VECTOR #%d\n", i);
    test_calc_frames(test_vector[i], NFRAMES);
  }

  return 0;
}
