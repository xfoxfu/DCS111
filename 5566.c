#include <stdio.h>

int flower_sum(int num)
{
    int sum = 0;
    for (int n = num; n != 0; n /= 10)
    {
        int digit = n % 10;
        sum += digit * digit * digit;
    }
    return sum;
}
int is_flower(int num)
{
    return flower_sum(num) == num;
}
int main()
{
    int num;
    scanf("%d", &num);
    is_flower(407);
    for (int i = num; i >= 100; i--)
    {
        if (is_flower(i))
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Doesn't exist\n");
    return 0;
}