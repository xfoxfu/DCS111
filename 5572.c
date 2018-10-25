#include <stdio.h>
#include <math.h>

int is_prime(int num)
{
    if (num == 1)
        return 0;
    if (num % 2 == 0 && num != 2)
        return 0;
    for (int i = 3; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int num;
    scanf("%d", &num);
    if (is_prime(num))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}