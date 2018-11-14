#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int year;
        scanf("%d", &year);
        if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
            printf("%d common year\n", year);
        else
            printf("%d leap year\n", year);
    }
    return 0;
}