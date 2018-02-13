/* K&R2 exercise 5-8, page 112 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int leap_year_days = 0;
int year_days = 0;

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    /* check if valid date */
    if (leap > 1 ||
	(leap && (month == 2 && day > 28)) ||
	(!leap && (month == 2 && day > 29)) ||
	month <= 0 || month > 12 || day <= 0 ||
	(!month%2 && month != 8 && day > 30) ||
	((month%2 || month == 8) && day > 31))
	return -1;
    
    for (i = 1; i < month; i++)
	day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    /* check: if invalid set value to 0 */
    leap = (leap > 1) ? 0 : leap;
    yearday = ((yearday <= 0) ||
	       (leap && yearday > leap_year_days) ||
	       (!leap && yearday > year_days))
	? 0 : yearday;

    for (i = 1; yearday > daytab[leap][i]; i++)
	yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int m1, d1, m2, d2;
    int dy1, dy2;
    int j;
    for (j = 0; j < 13; j++)
    {
	leap_year_days += daytab[0][j];
	year_days += daytab[1][j];
    }
    
    
    /* valid */
    month_day(1988, 60, &m1, &d1);
    dy1 = day_of_year(1989, 10, 14);
    printf("month: %d\t day: %d\n", m1, d1);
    printf("day of year: %d\n", dy1);

    /* invalid input */
    month_day(1988, 368, &m2, &d2);
    dy2 = day_of_year(1989, 13, 1);
    printf("month: %d\t day: %d\n", m2, d2);
    printf("day of year: %d\n", dy2);

    return 0;
}
