#include <stdio.h>

typedef struct
{
    char name[10];
    int days;
} Month;

int main()
{
    int year, firstDay, month;
    scanf("%d%d%d", &year, &firstDay, &month);
    const Month MONTHS[12] = {
        {"January", 31},
        {"February", !(year % 4) && (year % 100 || !(year % 400)) ? 29 : 28},
        {"March", 31},
        {"April", 30},
        {"May", 31},
        {"June", 30},
        {"July", 31},
        {"August", 31},
        {"September", 30},
        {"October", 31},
        {"November", 30},
        {"December", 31},
    };
    const char daysName[7][4] = {
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Thu",
        "Fri",
        "Sat"};
    const Month current_month = MONTHS[month - 1];
    printf("%s %d\n", current_month.name, year);
    int i; // loop var
    for (i = 0; i < 7; i++)
        printf("%8s", daysName[i]);
    printf("\n");
    int weekday = firstDay;
    for (i = 0; i < month - 1; i++)
        weekday += MONTHS[i].days;
    weekday %= 7;
    for (i = 0; i < weekday; i++)
        printf("%8c", ' ');
    for (i = 1; i <= current_month.days; i++)
    {
        printf("%8d", i);
        if ((!((weekday + i) % 7)) || i == current_month.days)
            printf("\n");
    }
    return 0;
}