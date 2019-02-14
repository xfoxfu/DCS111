#include <stdio.h>

int count(int h, int s);
int main()
{
    int h, s;
    scanf("%d%d", &h, &s);
    printf("%d\n", count(h, s));
    return 0;
}

int count(int h, int s)
{
    // static int go[1000];
    // static int *go_top = go;

    int result = 0;
    if (h <= 1)
    {
        // go_top--;
        return 1;
    }
    for (int i = 1; i <= s && i <= h; i++)
    {
        // *(go_top++) = i;
        result += count(h - i, s);
        // printf("<%d,%d> = %d\n", h, i, result);
    }
    // printf("%d=%d\n", h, result);
    // for (int *pgo = go; pgo < go_top; pgo++)
    //     printf("%d", *pgo);
    // putchar('\n');
    return result;
}