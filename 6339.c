#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int matrix[15][15] = {0};
    int line = 0;
    int row = n / 2;
    matrix[line][row] = 1;
    for (int num = 2; num <= n * n; num++)
    {
        int prev_line = line;
        int prev_row = row;
        line--;
        row++;
        if (row >= n)
            row = 0;
        if (line < 0)
            line = n - 1;
        if (matrix[line][row] != 0 || (prev_line == 0 && prev_row == n - 1))
        {
            line = prev_line + 1;
            row = prev_row;
        }
        matrix[line][row] = num;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", matrix[i][j]);
        putchar('\n');
    }
    return 0;
}