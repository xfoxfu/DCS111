#include <stdio.h>

#define LOCAL_MAIN_
#define DEBUG_

#ifdef LOCAL_MAIN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

short *safe_access(short *arr, int size, int i)
{
    if (i >= size)
    {
#ifdef DEBUG
        printf("[DEBUG]<WARNING> invalid access to arr %d >= %d", i, size);
#endif
    }
    return &arr[size];
}
int max(int a, int b)
{
    return a > b ? a : b;
}
short *plus(short *lhs, short *rhs)
{
    short *result;

    int i_lhs, i_rhs;
    for (i_lhs = 0; lhs[i_lhs] >= 0; i_lhs++)
        ;
    for (i_rhs = 0; rhs[i_rhs] >= 0; i_rhs++)
        ;
    i_lhs -= 1;
    i_rhs -= 1;

    int size = max(i_lhs, i_rhs) + 2;
    result = malloc(sizeof(short) * (size + 1));
    // set last digit
    int i_result = size;
    result[i_result--] = -1;
    // set all to zero
    for (int i = 0; i <= i_result; i++)
    {
        result[i] = 0;
    }

    for (; i_lhs >= 0 || i_rhs >= 0; i_lhs--, i_rhs--, i_result--)
    {
        short l_add = i_lhs >= 0 ? lhs[i_lhs] : 0;
        short r_add = i_rhs >= 0 ? rhs[i_rhs] : 0;
        result[i_result] += l_add + r_add;
        if (result[i_result] >= 10) // BUG
        {
            result[i_result - 1] = result[i_result] / 10;
            result[i_result] %= 10;
        }
    }
    if (result[0]) // BUG
    {
        return result;
    }
    else
    {
        short *result_part = malloc(size * sizeof(short));
        memcpy(result_part, result + 1, size * sizeof(short));
        free(result);
        return result_part;
    }
}

#ifdef LOCAL_MAIN
#define MAXl (100 + 1)

int main()
{
#ifdef DEBUG
    freopen("5814.in", "r", stdin);
#endif
    short s1[MAXl], s2[MAXl];
    int l1, l2, i;
    scanf("%d", &l1);
    for (i = 0; i < l1; ++i)
        scanf("%hd", s1 + i);
    scanf("%d", &l2);
    for (i = 0; i < l2; ++i)
        scanf("%hd", s2 + i);
    s1[l1] = s2[l2] = -1;
    short *plus(short *, short *);
    short *ans = plus(s1, s2);
    for (i = 0; s1[i] >= 0; ++i)
        printf("%hd", s1[i]);
    printf("\n");
    for (i = 0; s2[i] >= 0; ++i)
        printf("%hd", s2[i]);
    printf("\n");
    for (i = 0; ans[i] >= 0; ++i)
        printf("%hd", ans[i]);
    printf("\n");
    free(ans);
    return 0;
}
#endif