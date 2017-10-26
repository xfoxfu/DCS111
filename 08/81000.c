#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int max = -1, min = -1;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (max < 0 || a > max)
            max = a;
        if (min < 0 || a < min)
            min = a;
    }
    printf("%d %d\n", max, min);
    return 0;
}