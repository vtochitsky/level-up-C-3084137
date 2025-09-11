#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t timer;
  struct tm *tms;

  timer = time(NULL);
  tms = localtime(&timer);
  printf("Today is %s", asctime(tms)); /* not exact output string deu to time, short names */

  /* caclulate next Monday */
  tms->tm_mday = tms->tm_mday + (8 - tms->tm_wday); /* month day + (days_to_next_monday) */

  timer = mktime(tms);
  tms = localtime(&timer);
  printf("Next Monday will be the %s", asctime(tms)); /* not exact output string deu to time, short names */

  return 0;
}
