#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int A[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            printf("%d", A[i]);
            if (i != n - 1)
                printf(" ");
        }
    }
    printf("\n");
    return 0;
}