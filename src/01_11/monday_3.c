#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* validation function depends on mktime implementation. so the range of dates is restricted */

static int is_date_correct(const int day, const int month, const int year);

int main(void)
{
  int mday; /* day of month (1...31*) */
  int mon;  /* month (1...12) */
  int year; /* year (>= 1970 [see mktime() limitation]) */

  puts("Enter a valid date in format dd/mm/yyyy (1..31*/1..12/1970..3001):");
  scanf("%d/%d/%d", &mday, &mon, &year);
  if (0 == is_date_correct(mday, mon, year))
  {
    fprintf(stderr, "Invalid date. Exit.\n");
    return 1; /* program exit */
  }

  printf("You've entered valid date\n");

  return 0;
}

/*
The function returns 1(true) if date is correct.
The function returns 0(false) if date is incorrect.
*/
static int is_date_correct(const int day, const int month, const int year)
{
  putenv("TZ=UTC");
  tzset();

  struct tm date = {0};
  date.tm_mday = day;
  date.tm_mon = month - 1;    // tm_mon is 0-based
  date.tm_year = year - 1900; // tm_year is years since 1900

  /* Normalize the date */
  if (mktime(&date) == -1)
    return 0;

  return date.tm_mday == day && date.tm_mon == month - 1 && date.tm_year == year - 1900;
}
