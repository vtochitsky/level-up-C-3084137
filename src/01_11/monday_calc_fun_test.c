#include <stdio.h>
#include <assert.h>
#include "monday_calc_fun.h"

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

  /* Ancient Time Test Cases */

  run_test("Ancient date within same month",
           3, 10, 5, 1200, 15, 5, 1200);

  run_test("Ancient date within same month",
           6, 10, 6, 1200, 12, 6, 1200);

  run_test("Ancient leap year February",
           0, 27, 2, 1600, 28, 2, 1600);

  run_test("Ancient leap year February",
           1, 28, 2, 1600, 6, 3, 1600);

  run_test("Ancient year rollover",
           1, 30, 12, 999, 6, 1, 1000);

  run_test("Ancient non-leap February",
           0, 28, 2, 1700, 1, 3, 1700);

  /* Future Time Test Cases */

  run_test("Future date within same month",
           3, 10, 6, 3025, 15, 6, 3025);

  // run_test("Future leap year February",
  //          2, 27, 2, 2400, 4, 3, 2400);

  // run_test("Future year rollover",
  //          2, 30, 12, 2999, 5, 1, 3000);

  // run_test("Future non-leap February",
  //          2, 28, 2, 2100, 6, 3, 2100);

  printf("All tests completed.\n");

  return 0;
}
