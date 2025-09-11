#include <stdio.h>
#include <time.h>

/*
  implemented using stdlib functions.
  drawback: month's day is not ordinal but cardinal number
*/

int main(void)
{
  enum
  {
    plausible_timestr_len = 10, /* converted time to str should have length greater that it */
    timestr_len = 64
  };

  time_t timer;
  struct tm *tms;
  char timestr[timestr_len];

  timer = time(NULL);
  tms = localtime(&timer);

  if (strftime(timestr, sizeof(timestr), "%A, %B %d, %Y\n", tms) < plausible_timestr_len)
    fprintf(stderr, "Time to string convertion error.\n");

  printf("Today is %s", timestr);

  tms->tm_mday = tms->tm_mday + (8 - tms->tm_wday); /* month day + (days_to_next_monday) */

  timer = mktime(tms);
  tms = localtime(&timer);

  if (strftime(timestr, sizeof(timestr), "%d of %B\n", tms) < plausible_timestr_len)
    fprintf(stderr, "Time to string convertion error.\n");

  printf("Next Monday will be the %s", timestr);

  return 0;
}
