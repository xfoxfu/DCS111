#include <stdio.h>

#define MAX_SIZE 10

// @return next value
int fill_round(int init, int r, int size, int MAT[MAX_SIZE][MAX_SIZE])
{
    int value = init;
    int i; // loop var
    for (i = r; i < size - r; i++, value++)
        MAT[r][i] = value;
    for (i = r + 1; i < size - r; i++, value++)
        MAT[i][size - 1 - r] = value;
    for (i = size - 2 - r; i >= r; i--, value++)
        MAT[size - 1 - r][i] = value;
    for (i = size - 2 - r; i > r; i--, value++)
        MAT[i][r] = value;
    return value;
}
int main()
{
    int size;
    scanf("%d", &size);
    if (size > MAX_SIZE)
    {
        printf("size too large!");
        return 1;
    }
    int MAT[MAX_SIZE][MAX_SIZE];
    int i; // loop var
    int value = 1;
    for (i = 0; i <= (size + 1) / 2 - 1; i++)
        value = fill_round(value, i, size, MAT);
    int j; // loop var
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d", MAT[i][j]);
            if (j != size - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}