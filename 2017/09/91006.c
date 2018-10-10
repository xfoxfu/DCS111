#include <stdio.h>

int main()
{
    const char monthsName[12][10] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
    const char daysName[7][10] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"};
    int year, firstDay;
    scanf("%d%d", &year, &firstDay);
    const char daysOfMonth[12] = {
        31,
        !(year % 4) && (year % 100 || !(year % 400)) ? 29 : 28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31};
    int weekday = firstDay;
    for (int i = 0; i < 12; i++)
    {
        printf("%s 1, %d is %s\n", monthsName[i], year, daysName[weekday % 7]);
        weekday += daysOfMonth[i];
    }
    return 0;
}