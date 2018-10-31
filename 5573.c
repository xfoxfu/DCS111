#include <stdio.h>

int int_pow(int base, int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
        res *= base;
    return res;
}
int is_valid(int num, int n)
{
    int sum = 0;
    for (int num_remain = num; num_remain != 0; num_remain /= 10)
    {
        int digit = num_remain % 10;
        int add = int_pow(digit, n);
        sum += add;
    }
    return sum == num;
}
int main()
{
    int n;
    scanf("%d", &n);
    // is_valid(153, n);
    for (int i = int_pow(10, n - 1); i < int_pow(10, n); i++)
    {
        if (is_valid(i, n))
            printf("%d\n", i);
    }
    return 0;
}