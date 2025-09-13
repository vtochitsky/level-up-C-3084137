#include "monday_calc_fun.h"

const char *const DAYS[N_DAYS] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"};

const char *const MONTHS[N_MONTHS] = {
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"};

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

/*
The function returns 1(true) if year is leap.
The function returns 0(false) if year is NOT leap.
*/
int is_leap_year(const int year)
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

/*
This function calcualtes next Monday date.
Input/output:
  weekday: 0 Sanday ... 6 Saturday
  monthday: 1..31(30,29,28)
  month: 1..12
  year: >= 0
The function returns 0 in case of success.
Otherwise it returns 1. But it is not implemented so the function always returns 0.
*/
int calc_next_monday(int weekday, int *monthday, int *month, int *year)
{
  int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (is_leap_year(*year))
    days_in_month[1] = 29;

  int days_to_next_monday = weekday == 0 ? 1 : (8 - weekday);

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
