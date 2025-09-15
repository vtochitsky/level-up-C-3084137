#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frame
{
  int first;
  int second;
  int third;
  int total;
} frame_t;

#define NFRAMES 10
frame_t frames[NFRAMES];

int get_score(int frame_number, const char *message);
void calc_frame_table(frame_t *frames, int nframes, int frame);
void print_frame_table(frame_t *frames, int nframes, int frame);

int main(void)
{
  int fcnt = 0;
  int score = 0;

  while (fcnt < NFRAMES)
  {
    /* 1st roll */
    frames[fcnt].first = get_score(fcnt, "1st");

    /* if no strike OR if the last frame then 2nd roll*/
    if (10 != frames[fcnt].first || NFRAMES - 1 == fcnt)
    {
      frames[fcnt].second = get_score(fcnt, "2nd");
    }
    /* if the last frame AND 2nd is not 0 AND 1st plus 2nd is spare at least */ // TODO: clarify
    if (NFRAMES - 1 == fcnt && 0 != frames[fcnt].second && (frames[fcnt].first + frames[fcnt].second) >= 10)
    {
      frames[fcnt].third = get_score(fcnt, "3rd");
    }
    calc_frame_table(frames, NFRAMES, fcnt);
    print_frame_table(frames, NFRAMES, fcnt);
    fcnt++;
  }

  return 0;
}

int get_score(int frame_number, const char *message)
{
  int result;
  printf("Enter points for #%d frame, %s roll:", frame_number + 1, message);
  scanf("%d", &result);
  return result;
}

void calc_frame_table(frame_t *frames, int nframes, int frame)
{
  int previos = 0;
  if (frame > 0)
    previos += frames[frame - 1].total;
  frames[frame].total = previos + frames[frame].first + frames[frame].second + frames[frame].third;
  // recalculate back previos frames in case of strike(s) or spare(s)
  // TODO: implement me ...
}

void print_frame_table(frame_t *frames, int nframes, int frame)
{
  char frst[4];
  char scnd[4];
  char thrd[4];

  for (int i = 0; i <= frame; i++)
  {
    *frst = 0;
    *scnd = 0;
    *thrd = 0;
    if (10 == frames[i].first)
    {
      strcpy(scnd, "X");
    }
    else if (10 == frames[i].first + frames[i].second)
    {
      strcpy(scnd, "/");
    }
    else if (0 == frames[i].first + frames[i].second)
    {
      strcpy(scnd, "-");
    }
    else
    {
      itoa(frames[i].first, frst, 10);
      itoa(frames[i].second, scnd, 10);
    }
    if (i != nframes - 1)
    {
      printf("[%2s,%2s,%3d]", frst, scnd, frames[i].total);
    }
  }

  if (nframes - 1 == frame)
  {
    itoa(frames[frame].first, frst, 10);
    itoa(frames[frame].second, scnd, 10);
    itoa(frames[frame].third, thrd, 10);

    if (0 == frames[frame].first)
    {
      strcpy(frst, "-");
    }

    if (0 == frames[frame].second)
    {
      strcpy(scnd, "-");
    }

    if (0 == frames[frame].third)
    {
      strcpy(thrd, "-");
    }

    if (10 == frames[frame].first)
    {
      strcpy(frst, "X");
    }

    if (10 == frames[frame].second)
    {
      strcpy(scnd, "X");
    }

    if (10 == frames[frame].third)
    {
      strcpy(thrd, "X");
    }

    if (10 != frames[frame].first && 10 == frames[frame].first + frames[frame].second)
    {
      strcpy(frst, "");
      strcpy(scnd, "/");
    }

    printf("[%2s,%2s,%2s,%3d]", frst, scnd, thrd, frames[frame].total);
  }
  puts("");
}
