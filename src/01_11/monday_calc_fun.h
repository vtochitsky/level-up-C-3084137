#ifndef _MONDAY_CALC_FUN_H_
#define _MONDAY_CALC_FUN_H_

enum
{
  N_DAYS = 7,
  N_MONTHS = 12,
};

extern const char *const DAYS[N_DAYS];
extern const char *const MONTHS[N_MONTHS];

/*
// it can be defined here as static also.
// then a copy will be allocated for each .c with include of this file

static const char *const DAYS[N_DAYS] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"};

static const char *const MONTHS[N_MONTHS] = {
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
*/

char *ordinal(int v);
int is_leap_year(const int year);
int calc_next_monday(int weekday, int *monthday, int *month, int *year);

#endif /*# _MONDAY_CALC_FUN_H_ */