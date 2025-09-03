#include <stdio.h>
#include <stdbool.h>

/*
Function returns an int TRUE(1) if year is leap, otherwise it returns FALSE(0)
*/
int leapyear(const int year);

/* constants for the test */
enum
{
  StartYear = 1582u,
  StopYear = 2101u,
};

enum
{
  FALSE = 0,
  TRUE = 1
};

int main(void)
{

  /* Test leapyear function as it is suggested in the task */
  printf("Print only leap years (in the range [%zu...%zu]):\n", StartYear, StopYear);
  for (size_t yr = StartYear; yr <= StopYear; yr++)
  {
    if (TRUE == leapyear(yr))
    {
      printf("%zu\n", yr);
    }
  }

  return 0;
}

/*
Leap year rules:
1. if the year is evenly divisible by 4, it's a leap year;
2. Unless the year is also evenly divisible by 100, in which case it's not a leap year;
3. Unless the same year is also divisible by 400, in which case it is a leap year.
*/
int leapyear(const int year)
{
  int result = (int)false;

  /* 1. if the year is evenly divisible by 4, it's a leap year; */
  if (0 == year % 4)
  {
    result = (int)true;
  }

  /* 2. Unless the year is also evenly divisible by 100, in which case it's not a leap year; */
  if (0 == year % 100)
  {
    result = (int)false;
  }

  /* 3. Unless the same year is also divisible by 400, in which case it is a leap year. */
  if (0 == year % 400)
  {
    result = (int)true;
  }

  return result;
}
