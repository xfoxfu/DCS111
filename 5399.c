#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", a);
    }
    return 0;
}