#include <stdio.h>
#include <time.h>
#include <string.h>

/*
  implemented using stdlib functions.
  ordinal numbers are supported.
*/

char *ordinal(int v);

int main(void)
{
  enum
  {
    mday_suffix_len = 3,
    year_suffix_len = 5,
    month_suffix_len = 12,
    plausible_timestr_len = 10, /* converted time to str should have length greater that it */
    timestr_len = 64
  };

  time_t timer;
  struct tm *tms;
  char timestr[timestr_len];
  char year_suffix[year_suffix_len];
  char month_suffix[month_suffix_len];

  timer = time(NULL);
  tms = localtime(&timer);

  /* conveting date to proper string */
  if (strftime(timestr, sizeof(timestr), "%A, %B %d", tms) < plausible_timestr_len)
    fprintf(stderr, "Month, Day to string convertion error.\n");

  /* add ordinal suffix */
  strncat(timestr, ordinal(tms->tm_mday), mday_suffix_len);

  strncat(timestr, ", ", 3);

  if (strftime(year_suffix, sizeof(year_suffix), "%Y", tms) < year_suffix_len - 1)
    fprintf(stderr, "Year to string convertion error.\n");

  strncat(timestr, year_suffix, year_suffix_len);

  /* print it out */
  printf("Today is %s\n", timestr);

  /* calculate next Monday */
  tms->tm_mday = tms->tm_mday + (8 - tms->tm_wday); /* month day + (days_to_next_monday) */

  timer = mktime(tms);
  tms = localtime(&timer);

  if (strftime(timestr, sizeof(timestr), "%d", tms) < 1) /* ! */
    fprintf(stderr, "Day to string convertion error.\n");

  /* add ordinal suffix */
  strncat(timestr, ordinal(tms->tm_mday), mday_suffix_len);

  strncat(timestr, " of ", 6);

  if (strftime(month_suffix, sizeof(month_suffix), "%B", tms) < 4) /* ! */
    fprintf(stderr, "Month to string convertion error.\n");

  strncat(timestr, month_suffix, month_suffix_len);

  printf("Next Monday will be the %s\n", timestr);

  return 0;
}

char *ordinal(int v)
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
