#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IO_REDIR

typedef struct
{
    short digits[2002];
    short digit_count;
} BigInt;

BigInt read_bigint()
{
    BigInt result;
    result.digit_count = 0;
    char str[1002];
    scanf("%s", str);
    for (int i = strlen(str) - 1; i >= 0; i--)
        result.digits[result.digit_count++] = str[i] - '0';
    return result;
}
BigInt llu2bigint(unsigned long long num)
{
    BigInt result;
    result.digit_count = 0;
    for (; num != 0; num /= 10)
        result.digits[result.digit_count++] = num % 10;
    return result;
}
void print_bigint(BigInt num)
{
    for (int i = num.digit_count - 1; i >= 0; i--)
        putchar(num.digits[i] + '0');
    putchar('\n');
}

BigInt add(BigInt lhs, BigInt rhs)
{
    BigInt result;
    result.digit_count = 0;
    result.digits[0] = 0;
    for (int i = 0; i < ((lhs.digit_count > rhs.digit_count) ? lhs.digit_count : rhs.digit_count); i++)
    {
        short l_digit = i < lhs.digit_count ? lhs.digits[i] : 0;
        short r_digit = i < rhs.digit_count ? rhs.digits[i] : 0;
        short digit = l_digit + r_digit + result.digits[result.digit_count];
        result.digits[result.digit_count++] = digit % 10;
        result.digits[result.digit_count] = digit / 10;
    }
    if (result.digits[result.digit_count] != 0)
        result.digit_count++;
    return result;
}
BigInt multiply_single(BigInt lhs, short rhs, short prepend)
{
    BigInt result;
    result.digit_count = 0;
    for (int i = 0; i < prepend; i++)
        result.digits[result.digit_count++] = 0;
    result.digits[result.digit_count] = 0;
    for (int i = 0; i < lhs.digit_count; i++)
    {
        short digit = lhs.digits[i] * rhs + result.digits[result.digit_count];
        result.digits[result.digit_count++] = digit % 10;
        result.digits[result.digit_count] = digit / 10;
    }
    if (result.digits[result.digit_count] != 0)
        result.digit_count++;
    // print_bigint(result); // debug
    return result;
}
BigInt multiply(BigInt lhs, BigInt rhs)
{
    BigInt result;
    result.digit_count = 0;
    result.digits[0] = 0;
    for (int i = 0; i < rhs.digit_count; i++)
    {
        result = add(result, multiply_single(lhs, rhs.digits[i], i));
    }
    return result;
}

int main()
{
#ifdef IO_REDIR
    freopen("6199.in", "r", stdin);
    freopen("6199.out", "w", stdout);
#endif
    BigInt lhs = read_bigint();
    BigInt rhs = read_bigint();
    // print_bigint(lhs);
    // print_bigint(rhs);
    // print_bigint(add(lhs, rhs));
    // print_bigint(multiply_single(lhs, 2, 5));
    print_bigint(multiply(lhs, rhs));
    return 0;
}
