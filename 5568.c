#include <stdio.h>
#include <string.h>

typedef struct Bignum
{
    char digits[100];
    int digit_count;
} Bignum;

typedef struct MulSingleResult
{
    int digit;
    int previous_digit;
} MulSingleResult;

MulSingleResult mul_single(int digit, int rhs, int digit_add)
{
    digit *= rhs;
    digit += digit_add;
    MulSingleResult result;
    result.digit = digit % 10;
    result.previous_digit = digit / 10;
    return result;
}
Bignum multiply(Bignum lhs, int rhs)
{
    MulSingleResult single_result;
    single_result.previous_digit = 0;
    for (int i = 0; i < lhs.digit_count; i++)
    {
        single_result = mul_single(lhs.digits[i] - '0', rhs, single_result.previous_digit);
        lhs.digits[i] = single_result.digit + '0';
    }
    if (single_result.previous_digit > 0)
    {
        lhs.digits[lhs.digit_count++] = single_result.previous_digit + '0';
    }
    return lhs;
}

int main()
{
    Bignum result;
    result.digits[0] = '1';
    result.digit_count = 1;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        result = multiply(result, 3);
    }
    for (int i = result.digit_count - 1; i >= 0; i--)
    {
        printf("%c", result.digits[i]);
    }
    printf("\n");
    return 0;
}