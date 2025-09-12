#include <stdio.h>
#include <time.h>
#include <string.h>

/*
  implemented using stdlib functions;
  ordinal days' numbers are supported;
  calcualtion is made by single function calc_next_Monday()
*/

static char *ordinal(int v);
static void print_start_day(struct tm *t);
static void print_next_Monday(struct tm *t);
struct tm *calc_next_Monday(struct tm *t);

int main(void)
{
  time_t timer;
  struct tm *tms;

  /* get current month day and day of week */
  timer = time(NULL);
  tms = localtime(&timer);

  print_start_day(tms);

  /* calculate next Monday */
  tms = calc_next_Monday(tms); // or just calc_next_Monday(tms);

  print_next_Monday(tms);

  return 0;
}

static char *ordinal(int v)
{
  /* catch exceptions */
  if (11 == v || 12 == v || 13 == v)
    return ("th");

  /* everything else is consistent */
  v %= 10;
  if (1 == v)
    return ("st");
  if (2 == v)
    return ("nd");
  if (3 == v)
    return ("rd");
  return ("th");
}

static void print_start_day(struct tm *t)
{
  enum
  {
    buff_len = 12,
    timestr_len = 64
  };

  char buff[buff_len];
  char timestr[timestr_len];

  /* conveting date to proper string */
  if (strftime(timestr, timestr_len, "%A, %B %d", t) < 10) /* constant 10 is not nice */
    fprintf(stderr, "Month, Day to string convertion error.\n");

  /* add ordinal suffix */
  strncat(timestr, ordinal(t->tm_mday), 3); /* constant 3 is not nice */

  strncat(timestr, ", ", 3); /* constant 3 is not nice */

  if (strftime(buff, buff_len, "%Y", t) < 4) /* constant 4 is not nice */
    fprintf(stderr, "Year to string convertion error.\n");

  strncat(timestr, buff, buff_len);

  /* print it out */
  printf("Today is %s\n", timestr);
}

static void print_next_Monday(struct tm *t)
{
  enum
  {
    buff_len = 12,
    timestr_len = 64
  };

  char buff[buff_len];
  char timestr[timestr_len];

  if (strftime(timestr, sizeof(timestr), "%d", t) < 1) /* constant 1 is not nice */
    fprintf(stderr, "Day to string convertion error.\n");

  /* add ordinal suffix */
  strncat(timestr, ordinal(t->tm_mday), 3); /* constant 3 is not nice */

  strncat(timestr, " of ", 6); /* constant 6 is not nice */

  if (strftime(buff, buff_len, "%B", t) < 4) /* constant 4 is not nice */
    fprintf(stderr, "Month to string convertion error.\n");

  strncat(timestr, buff, buff_len);

  printf("Next Monday will be the %s\n", timestr);
}

struct tm *calc_next_Monday(struct tm *t)
{
  time_t tt;
  t->tm_mday = t->tm_mday + (8 - t->tm_wday); /* month day + (days to next Monday) */

  /* re-normalize date */
  tt = mktime(t);
  t = localtime(&tt);
}
