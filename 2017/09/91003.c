#include <stdio.h>

int sumDigits(int num, int base)
{
    int division = 1;
    int sum = 0;
    int digit;
    while ((digit = num / division))
    {
        sum += digit % base;
        division *= base;
    }
    return sum;
}
int main()
{
    printf("%d", 2992);
    int num; // loop var
    for (num = 2993; num <= 9999; num++)
    {
        if (sumDigits(num, 10) == sumDigits(num, 12) &&
            sumDigits(num, 12) == sumDigits(num, 16))
            printf("\n%d", num);
    }
    return 0;
}