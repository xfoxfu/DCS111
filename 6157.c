#include <stdio.h>

int sum_factor(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    return sum;
}
int main()
{
    int num_max;
    scanf("%d", &num_max);
    for (int i = 1; i < num_max; i++)
    {
        if (sum_factor(i) == i)
            printf("%d\n", i);
    }
    return 0;
}