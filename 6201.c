#include <stdio.h>
#include <math.h>

int qpow(int k, int e)
{
    int r = 1;
    for (int i = 1; i <= e; i++)
        r *= k;
    return r;
}
int solve_pow(int k, int n)
{
    if (n <= 0)
        return 0;
    int max_power = log2(n);
    int remain_n = n - qpow(2, max_power);
    // printf("[DEBUG]solve n=%d max_power=%d remain_n=%d\n", n, max_power, remain_n);

    int pow_a = qpow(k, max_power);
    int pow_b = solve_pow(k, remain_n);
    return pow_a + pow_b;
}
int main()
{
    int k, n;
    scanf("%d%d", &k, &n);
    printf("%d\n", solve_pow(k, n));
    return 0;
}
