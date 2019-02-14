#include <stdio.h>

int jpow(int n)
{
    int r = 1;
    for (; n >= 1; n--)
        r *= n;
    return r;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%5d", jpow(i) / (jpow(j) * jpow(i - j)));
        }
        putchar('\n');
    }
    return 0;
}