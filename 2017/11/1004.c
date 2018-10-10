#include <stdio.h>

#define MAX_SIZE 10

void op(int n)
{
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int matrixC[MAX_SIZE][MAX_SIZE] = {0};
    int i, j; // loop var
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrixB[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int k; // loop var
            for (k = 0; k < n; k++)
            {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", matrixC[i][j]);
            if (j != n - 1)
                printf(" ");
        }
        printf("\n");
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        op(n);
    }
    return 0;
}