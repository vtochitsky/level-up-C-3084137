#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frame
{
  int first;
  int second;
  int third; // !!! only for frame #10
  int total;
} frame_t;

#define NFRAMES 10
frame_t frames[NFRAMES];
static inline int strike(frame_t frm);
static inline int spare(frame_t frm);
int get_score(int i, const char *message);
void calc_frame_table(frame_t *frames, int frames_length, int i);
void print_frame_table(frame_t *frames, int frames_length, int frame);

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
      frames[fcnt].second = 0;
      do
      {
        frames[fcnt].second = get_score(fcnt, "2nd");
        if (frames[fcnt].second > 10 - frames[fcnt].first && /* not frame #10 */ (10 - 1) != fcnt)
        {
          puts("Error: sum of 1st and 2nd can not be greater than 10!");
        }
        else
        {
          break;
        }
      } while (1);
    }
    /* if the last frame and spare or strike */
    if (NFRAMES - 1 == fcnt && (strike(frames[fcnt]) || spare(frames[fcnt])))
    {
      frames[fcnt].third = get_score(fcnt, "3rd");
    }
    calc_frame_table(frames, NFRAMES, fcnt);
    print_frame_table(frames, NFRAMES, fcnt);
    fcnt++;
  }

  return 0;
}

static inline int strike(frame_t frm)
{
  return 10 == frm.first;
}

static inline int spare(frame_t frm)
{
  return 10 != frm.first && 10 == (frm.first + frm.second);
}

int get_score(int i, const char *message)
{
  int result;
  int res;
  do
  {
    printf("Enter points for #%d frame, %s roll:", i + 1, message);
    res = scanf("%d", &result);

    if (res != 1)
    {
      /* Clean input buffer up: read and throw out all characters up to endo of string*/
      while (getchar() != '\n')
      { /* nothing is here */
      };
      puts("Invalid input. Please enter an integer.");
    }
  } while (res != 1);

  return result;
}

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
    printf("%d %d %d\n", frames[i].first, frames[i].second, frames[i].third);
    /* strike or spare */
    if (10 == frames[i].first || 10 == (frames[i].first + frames[i].second))
    {
      frames[i].total += frames[i].third;
    }
  }

  /* .total calculation for current frame  */
  int previous_total = i > 0 ? frames[i - 1].total : 0; /* previous_total is zero for the 1st frame */
  frames[i].total += frames[i].first + frames[i].second + previous_total;
}

void print_frame_table(frame_t *frames, int frames_length, int i)
{
  char frst[4];
  char scnd[4];
  char thrd[4];

  for (int idx = 0; idx <= i; idx++)
  {
    *frst = 0;
    *scnd = 0;
    *thrd = 0;
    if (10 == frames[idx].first)
    {
      strcpy(scnd, "X");
    }
    else if (10 == frames[idx].first + frames[idx].second)
    {
      strcpy(scnd, "/");
    }
    else if (0 == frames[idx].first + frames[idx].second)
    {
      strcpy(scnd, "-");
    }
    else
    {
      itoa(frames[idx].first, frst, 10);
      itoa(frames[idx].second, scnd, 10);
    }
    if (idx != frames_length - 1)
    {
      printf("[%2s,%2s,%3d]", frst, scnd, frames[idx].total);
    }
  }

  if (frames_length - 1 == i)
  {
    itoa(frames[i].first, frst, 10);
    itoa(frames[i].second, scnd, 10);
    itoa(frames[i].third, thrd, 10);

    if (0 == frames[i].first)
    {
      strcpy(frst, "-");
    }

    if (0 == frames[i].second)
    {
      strcpy(scnd, "-");
    }

    if (0 == frames[i].third)
    {
      strcpy(thrd, "-");
    }

    if (10 == frames[i].first)
    {
      strcpy(frst, "X");
    }

    if (10 == frames[i].second)
    {
      strcpy(scnd, "X");
    }

    if (10 == frames[i].third)
    {
      strcpy(thrd, "X");
    }

    if (10 != frames[i].first && 10 == frames[i].first + frames[i].second)
    {
      strcpy(frst, "");
      strcpy(scnd, "/");
    }

    printf("[%2s,%2s,%2s,%3d]", frst, scnd, thrd, frames[i].total);
  }
  puts("");
}
