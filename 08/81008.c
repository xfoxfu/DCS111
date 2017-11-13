#include <stdio.h>
#include <math.h>

#define DEBUG

int main()
{
    int a;
    scanf("%d", &a);
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i)
            continue;
        else
        {
            printf("No\n");
            return 0;
        }
    }
    if (a != 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}