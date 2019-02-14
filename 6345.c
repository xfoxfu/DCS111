#include <stdio.h>

int main()
{
    int size;
    while (scanf("%d", &size) != EOF)
    {
        int matrixA[10][10];
        int matrixB[10][10];
        int matrixC[10][10] = {0};
        // read input
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                scanf("%d", &matrixA[i][j]);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                scanf("%d", &matrixB[i][j]);
        // multiply
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++)
                    matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
        // output
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (j != 0)
                    putchar(' ');
                printf("%d", matrixC[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}