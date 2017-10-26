#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a > 100)
            printf("error");
        else if (a >= 90)
            printf("A");
        else if (a >= 80)
            printf("B");
        else if (a >= 70)
            printf("C");
        else if (a >= 60)
            printf("D");
        else if (a >= 0)
            printf("E");
        else
            printf("error");
        printf("\n");
    }
    return 0;
}