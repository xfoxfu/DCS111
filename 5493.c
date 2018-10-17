#include <stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    printf("%d\n", (year - 2001 + 1 + (year - 2001) / 4) % 7);
    return 0;
}