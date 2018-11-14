#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

void print_space(int n)
{
    for (int i = 0; i < n;i++)
    {
        printf(" ");
    }
}
int fill_round(int value, int r, int MAT[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = r; i < size - r; i++)
        MAT[r][i] = value++;
    for (int i = r + 1; i < size - r; i++)
        MAT[i][size - r - 1] = value++;
    for (int i = size - r - 2; i >= r; i--)
        MAT[size - r - 1][i] = value++;
    for (int i = size - r - 2; i > r; i--)
        MAT[i][r] = value++;
    return value;
}
int main()
{
    int size;
    scanf("%d", &size);
    int MAT[MAX_SIZE][MAX_SIZE];
    int value = 1;
    int x = 0;
    int y = 0;
    for (int i = 0; i <= size / 2; i++)
    {
        value = fill_round(value, i, MAT, size);
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d", MAT[i][j]);
            if (j != size - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}