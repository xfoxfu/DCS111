#include <stdio.h>

void printDigits(int num)
{
    int division = 64;
    int digit;
    while (division >= 1)
    {
        digit = num / division;
        printf("%d", digit % 2);
        division /= 2;
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    if (num >= 0)
    {
        printf("0");
        printDigits(num);
    }
    else
    {
        printf("1");
        printDigits(128 + num);
    }
    printf("\n");
    return 0;
}