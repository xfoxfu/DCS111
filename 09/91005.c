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
    const char daysName[7][4] = {
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Thu",
        "Fri",
        "Sat"};
    int year, firstDay, month;
    scanf("%d%d%d", &year, &firstDay, &month);
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
    printf("%s %d\n", monthsName[month - 1], year);
    int i; // loop var
    for (i = 0; i < 7; i++)
        printf("%8s", daysName[i]);
    printf("\n");
    int weekday = firstDay;
    for (i = 0; i < month - 1; i++)
        weekday += daysOfMonth[i];
    weekday %= 7;
    for (i = 0; i < weekday; i++)
        printf("%8c", ' ');
    for (i = 1; i <= daysOfMonth[month - 1]; i++)
    {
        printf("%8d", i);
        if ((!((weekday + i) % 7)) || i == daysOfMonth[month - 1])
            printf("\n");
    }
    return 0;
}