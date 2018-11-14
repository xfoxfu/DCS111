#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int max, min;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (i == 0)
        {
            max = num;
            min = num;
        }
        if (num > max)
            max = num;
        if (num < min)
            min = num;
    }
    printf("%d %d\n", max, min);
    return 0;
}