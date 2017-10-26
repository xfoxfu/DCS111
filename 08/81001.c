#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int year;
        scanf("%d", &year);
        if (!(year % 4) && (year % 100 || !(year % 400)))
            printf("%d leap year\n", year);
        else
            printf("%d common year\n", year);
    }
    return 0;
}