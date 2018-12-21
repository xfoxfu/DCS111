#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IO_REDIR

int main()
{
#ifdef IO_REDIR
    freopen("6195.in", "r", stdin);
    freopen("6195.out", "w", stdout);
#endif
    // handle input
    char matrix[50][50];
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        getchar();
        for (int j = 0; j < n; j++)
            matrix[i][j] = getchar();
    }
    int fword_count;
    scanf("%d", &fword_count);
    char fwords[10][100];
    for (int i = 0; i < fword_count; i++)
    {
        scanf("%s", fwords[i]);
    }
    // output
    char *str = calloc(m * n + 1, sizeof(char));
    char *pstr = str;
    for (int i = 0; i < ((m < n ? m : n) + 1) / 2; i++)
    {
        for (int a = i, b = i; a < m - i && b < n - i && a >= i && b >= i; a++)
            *(pstr++) = matrix[a][b];
        for (int a = m - i - 1, b = i + 1; a < m - i && b < n - i && a >= i && b >= i; b++)
            *(pstr++) = matrix[a][b];
        if (n - i - 1 > i)
            for (int a = m - i - 2, b = n - i - 1; a < m - i && b < n - i && a >= i && b >= i; a--)
                *(pstr++) = matrix[a][b];
        if (m - i - 1 > i)
            for (int a = i, b = n - i - 2; a < m - i && b < n - i && a >= i && b > i; b--)
                *(pstr++) = matrix[a][b];
    }
    *pstr = '\0';
    printf("%s\n", str);
    // transform
    for (int i = 0; i < fword_count; i++)
    {
        int len = strlen(fwords[i]);
        char *pos;
        while ((pos = strstr(str, fwords[i])) != NULL)
        {
            for (int i = 1; i < len; i++)
                pos[i] = '*';
        }
    }
    // output
    printf("%s\n", str);
    // clean up
    free(str);
    return 0;
}