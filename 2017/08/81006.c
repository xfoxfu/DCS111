#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int max;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (i == 0 || a > max)
            max = a;
    }
    printf("%d\n", max);
    return 0;
}