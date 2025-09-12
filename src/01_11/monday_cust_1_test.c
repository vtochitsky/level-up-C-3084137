#include <stdio.h>
#include <assert.h>

/* Function declarations */
static int is_leap_year(const int year);
int calc_next_monday(int weekday, int *monthday, int *month, int *year);

/* Logging helper */
void log_test_case(const char *desc, int weekday, int day, int month, int year,
                   int expected_day, int expected_month, int expected_year,
                   int actual_day, int actual_month, int actual_year)
{
  printf("Test: %s\n", desc);
  printf("   Input: weekday=%d, date=%02d/%02d/%04d\n", weekday, day, month, year);
  printf("   Expected: %02d/%02d/%04d\n", expected_day, expected_month, expected_year);
  printf("   Actual:   %02d/%02d/%04d\n", actual_day, actual_month, actual_year);
  if (expected_day == actual_day && expected_month == actual_month && expected_year == actual_year)
  {
    printf("[v] Passed\n\n");
  }
  else
  {
    printf("[x] Failed\n\n");
  }
}

/* Test runner */
void run_test(const char *desc, int weekday, int day, int month, int year,
              int expected_day, int expected_month, int expected_year)
{
  int actual_day = day, actual_month = month, actual_year = year;
  int result = calc_next_monday(weekday, &actual_day, &actual_month, &actual_year);
  assert(result == 0);
  log_test_case(desc, weekday, day, month, year,
                expected_day, expected_month, expected_year,
                actual_day, actual_month, actual_year);
}

int main()
{
  run_test("Regular weekday within same month",
           2, 10, 6, 2025, 16, 6, 2025);

  run_test("End of month transition",
           5, 28, 2, 2025, 3, 3, 2025);

  run_test("Leap year February",
           2, 27, 2, 2024, 4, 3, 2024);

  run_test("Year rollover",
           2, 30, 12, 2025, 5, 1, 2026);

  run_test("Already Monday",
           1, 7, 7, 2025, 14, 7, 2025);

  run_test("Last day of month",
           5, 31, 1, 2025, 3, 2, 2025);

  run_test("February 28 on non-leap year",
           2, 28, 2, 2023, 6, 3, 2023);

  printf("All tests completed.\n");
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
This function calcualtes next Monday date.
Input/output:
  weekday: 0 Sanday ... 6 Saturday
  monthday: 1..31(30,29,28)
  month: 1..12
  year: >= 0
The function returns 0 in case of success.
Otherwise it returns 1.
*/
int calc_next_monday(int weekday, int *monthday, int *month, int *year)
{
  int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (is_leap_year(*year))
    days_in_month[1] = 29;

  int days_to_next_monday = 8 - weekday;

  int next_day = *monthday + days_to_next_monday;
  if (next_day > days_in_month[*month - 1])
  {
    next_day -= days_in_month[*month - 1];
    (*month)++;
    if (*month > 12)
    {
      *month = 1;
      (*year)++;
    }
    *monthday = next_day;
  }
  else
  {
    *monthday = next_day;
  }

  return 0;
}
