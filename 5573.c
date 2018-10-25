#include <stdio.h>

int powb(int base, int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
        res *= base;
    return res;
}
int is_valid(int num, int n)
{
    int res = 0;
    for (int numb = num; numb != 0; numb /= 10)
    {
        int digit = numb % 10;
        int add = powb(digit, n);
        res += add;
    }
    return res == num;
}
int main()
{
    int n;
    scanf("%d", &n);
    // is_valid(153, n);
    for (int i = powb(10, n - 1); i < powb(10, n); i++)
    {
        if (is_valid(i, n))
            printf("%d\n", i);
    }
    return 0;
}