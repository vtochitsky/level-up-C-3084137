#include <stdio.h>
#include <assert.h>
#include "monday_calc_fun.h"

/* Logging helper */
int log_test_case(const char *desc, int weekday, int day, int month, int year,
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
    return 0;
  }
  else
  {
    printf("[x] Failed\n\n");
    return 1;
  }
}

/* Test runner */
int run_test(const char *desc, int weekday, int day, int month, int year,
             int expected_day, int expected_month, int expected_year)
{
  int actual_day = day, actual_month = month, actual_year = year;
  int result = calc_next_monday(weekday, &actual_day, &actual_month, &actual_year);
  assert(result == 0);
  return log_test_case(desc, weekday, day, month, year,
                       expected_day, expected_month, expected_year,
                       actual_day, actual_month, actual_year);
}

int main()
{
  int result = 0;

  result += run_test("Regular weekday within same month",
                     2, 10, 6, 2025, 16, 6, 2025);

  result += run_test("End of month transition",
                     5, 28, 2, 2025, 3, 3, 2025);

  result += run_test("Leap year February",
                     2, 27, 2, 2024, 4, 3, 2024);

  result += run_test("Year rollover",
                     2, 30, 12, 2025, 5, 1, 2026);

  result += run_test("Already Monday",
                     1, 7, 7, 2025, 14, 7, 2025);

  result += run_test("Last day of month",
                     5, 31, 1, 2025, 3, 2, 2025);

  result += run_test("February 28 on non-leap year",
                     2, 28, 2, 2023, 6, 3, 2023);

  /* Ancient Time Test Cases */

  result += run_test("Ancient date within same month",
                     3, 10, 5, 1200, 15, 5, 1200);

  result += run_test("Ancient date within same month",
                     6, 10, 6, 1200, 12, 6, 1200);

  result += run_test("Ancient leap year February",
                     0, 27, 2, 1600, 28, 2, 1600);

  result += run_test("Ancient leap year February",
                     1, 28, 2, 1600, 6, 3, 1600);

  run_test("Ancient year rollover",
           1, 30, 12, 999, 6, 1, 1000);

  result += run_test("Ancient non-leap February",
                     0, 28, 2, 1700, 1, 3, 1700);

  /* Future Time Test Cases */

  result += run_test("Future date within same month",
                     5, 10, 6, 3025, 13, 6, 3025);

  result += run_test("Future leap year February",
                     0, 27, 2, 2400, 28, 2, 2400);

  result += run_test("Future year rollover",
                     1, 30, 12, 2999, 6, 1, 3000);

  result += run_test("Future non-leap February",
                     0, 28, 2, 2100, 1, 3, 2100);

  if (0 == result)
  {
    printf("All tests passed.\n");
  }
  else
  {
    printf("Tests FAILED: %d.\n", result);
  }

  return 0;
}
