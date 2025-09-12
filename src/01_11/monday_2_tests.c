#include <stdio.h>
#include <assert.h>

/* Function declarations */
static int is_leap_year(const int year);
static int is_date_correct(const int day, const int month, const int year);

/* Function definitions */
static int is_leap_year(const int year)
{
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int is_date_correct(const int day, const int month, const int year)
{
  if (year < 0 || month < 1 || month > 12 || day < 1)
    return 0;

  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (is_leap_year(year))
    days_in_month[1] = 29;

  return day <= days_in_month[month - 1];
}

void test_is_leap_year(void)
{
  /* Leap years */
  assert(is_leap_year(2000) == 1); /* divisible by 400 */
  assert(is_leap_year(2024) == 1); /*  divisible by 4, not by 100 */
  assert(is_leap_year(1600) == 1); /*  divisible by 400 */
  assert(is_leap_year(0) == 1);
  assert(is_leap_year(4) == 1);
  assert(is_leap_year(400) == 1);
  assert(is_leap_year(-400) == 1);

  /* Non-leap years */
  assert(is_leap_year(1900) == 0); /* divisible by 100, not by 400 */
  assert(is_leap_year(2023) == 0); /* not divisible by 4 */
  assert(is_leap_year(2100) == 0); /* divisible by 100, not by 400 */
  assert(is_leap_year(1) == 0);
  assert(is_leap_year(100) == 0);
  assert(is_leap_year(9999) == 0);
  assert(is_leap_year(-100) == 0);
}

void test_is_date_correct(void)
{
  /* Valid edge cases */
  assert(is_date_correct(29, 2, 2024) == 1);  /* Leap year */
  assert(is_date_correct(28, 2, 2023) == 1);  /* Non-leap year */
  assert(is_date_correct(31, 1, 2023) == 1);  /* January */
  assert(is_date_correct(30, 4, 2023) == 1);  /* April */
  assert(is_date_correct(31, 12, 2023) == 1); /* December */

  /* Invalid edge cases */
  assert(is_date_correct(0, 1, 2023) == 0);   /*  Day < 1 */
  assert(is_date_correct(32, 1, 2023) == 0);  /*  Day > 31 */
  assert(is_date_correct(31, 4, 2023) == 0);  /*  April has 30 days */
  assert(is_date_correct(29, 2, 2023) == 0);  /*  Not a leap year */
  assert(is_date_correct(15, 0, 2023) == 0);  /*  Month < 1 */
  assert(is_date_correct(15, 13, 2023) == 0); /*  Month > 12 */
  assert(is_date_correct(15, 6, -1) == 0);    /*  Negative year */
  assert(is_date_correct(31, 6, 2023) == 0);  /*  June has 30 days */
}

int main(void)
{
  test_is_leap_year();
  test_is_date_correct();
  printf("All tests passed successfully.\n");
  return 0;
}
