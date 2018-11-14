#include <stdio.h>

int sum_digits(int num, int base)
{
    int sum = 0;
    for (; num > 0; num /= base)
    {
        sum += num % base;
    }
    return sum;
}
int main()
{
    for (int i = 2991; i <= 9999; i++)
    {
        if (sum_digits(i, 10) == sum_digits(i, 12) && sum_digits(i, 12) == sum_digits(i, 16))
            printf("%d\n", i);
    }
    return 0;
}