#include <stdio.h>

int main()
{
    int source[3][3];
    int sourceT[3][3];
    int i, j; // loop var
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int a;
            scanf("%d", &a);
            source[i][j] = a;
        }
    }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            sourceT[i][j] = source[j][i];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sourceT[i][j]);
        }
    return 0;
}