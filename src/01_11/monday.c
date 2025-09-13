#include <stdio.h>
#include <time.h> /* only to get today date by function get_today_date() */
#include "monday_calc_fun.h"

static void get_today_date(int *weekday, int *monthday, int *month, int *year);

int main(void)
{
  int w_day, m_day, mon, year;

  /*
  w_day = 5;
  m_day = 12;
  mon = 9;
  year = 2025;
  */

  get_today_date(&w_day, &m_day, &mon, &year);

  printf("Today is %s, %02d%s of %s %04d\n", DAYS[w_day], m_day, ordinal(m_day), MONTHS[mon - 1], year);

  calc_next_monday(w_day, &m_day, &mon, &year);

  printf("Next Monday is %02d%s of %s %04d\n", m_day, ordinal(m_day), MONTHS[mon - 1], year);

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
