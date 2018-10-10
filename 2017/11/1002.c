#include <stdio.h>

#define SIZE 3

int main()
{
    float mainDiagMax = 0, subDiagMax = 0;
    float matrix[SIZE][SIZE];
    int i, j; // loop var
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    for (i = 0; i < SIZE; i++)
    {
        if (matrix[i][i] > mainDiagMax || i == 0)
        {
            mainDiagMax = matrix[i][i];
        }
        if (matrix[i][SIZE - 1 - i] > subDiagMax || i == 0)
        {
            subDiagMax = matrix[i][SIZE - 1 - i];
        }
    }
    printf("%.1f %.1f ", mainDiagMax, subDiagMax);
    return 0;
}