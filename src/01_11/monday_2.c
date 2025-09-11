#include <stdio.h>
#include <time.h>

static int is_leap_year(const int year);
static int is_date_correct(const int day, const int month, const int year);

int main(void)
{
  int mday; /* day of month (1 ... 31*) */
  int mon;  /* month (1=Jan ... 12=Dec) */
  int year; /* year (> 0) */

  puts("Enter a valid date in format dd/mm/yyyy:");

  scanf("%d/%d/%d", &mday, &mon, &year);

  if (0 == is_date_correct(mday, mon, year))
  {
    fprintf(stderr, "Invalid date. Exit.\n");
    return 1; /* program exit */
  }

  printf("You've entered valid date.\n");

  return 0;
}

/*
The function returns 1(true) if year is leap.
The function returns 0(false) if year is NOT leap.
*/
static int is_leap_year(const int year)
{
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/*
The function returns 1(true) if date is correct.
The function returns 0(false) if date is incorrect.
*/
static int is_date_correct(const int day, const int month, const int year)
{
  if (year < 0 || month < 1 || month > 12 || day < 1)
    return 0;

  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (is_leap_year(year))
    days_in_month[1] = 29;

  return day <= days_in_month[month - 1];
}
