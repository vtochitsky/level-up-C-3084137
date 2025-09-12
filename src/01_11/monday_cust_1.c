#include <stdio.h>
#include <time.h> /* only to get today date by function get_today_date() */

static char *ordinal(int v);
static int is_leap_year(const int year);
void get_today_date(int *weekday, int *monthday, int *month, int *year);
int calc_next_monday(int weekday, int *monthday, int *month, int *year);

int main(void)
{
  const char *week_days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  const char *months[12] = {
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
  int w_day, m_day, mon, year;

  // w_day = 5;
  // m_day = 12;
  // mon = 9;
  // year = 2025;
  get_today_date(&w_day, &m_day, &mon, &year);

  printf("Today is %s, %02d%s of %s %04d\n", week_days[w_day], m_day, ordinal(m_day), months[mon - 1], year);

  calc_next_monday(w_day, &m_day, &mon, &year);

  printf("Next Monday is %02d%s of %s %04d\n", m_day, ordinal(m_day), months[mon - 1], year);

  return 0;
}

static char *ordinal(int v)
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

/*
This function uses standard library functions declared in time.h: time() and localtime()
It outputs:
  weekday: 0 Sanday ... 6 Saturday
  monthday: 1..31(30,29,28)
  month: 1..12
  year: >= 1900
*/
void get_today_date(int *weekday, int *monthday, int *month, int *year)
{
  time_t t = time(NULL);
  struct tm *tt = localtime(&t);
  *weekday = tt->tm_wday;
  *monthday = tt->tm_mday;
  *month = tt->tm_mon + 1;    /* due to tm_mon is 0..11 */
  *year = tt->tm_year + 1900; /* due to tm_year counts from 1900 */
}
