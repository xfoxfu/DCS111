#include <stdio.h>
// #include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= 3; i++)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("%d\n", sum);
    return 0;
}