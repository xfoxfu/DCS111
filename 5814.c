#include <stdio.h>

#define LOCAL_MAIN
#define DEBUG

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
short *plus(short *const lhs, short *const rhs)
{
    short *result;

    short *lhs_end;
    short *rhs_end;
    for (lhs_end = lhs; *lhs_end >= 0; lhs_end++)
        ;
    for (rhs_end = rhs; *rhs_end >= 0; rhs_end++)
        ;

    int size = max(lhs_end - lhs, rhs_end - rhs) + 1;
    result = calloc(size + 1, sizeof(*result));
    // set last digit
    short *res_end = result + size; // &result[size]
    *res_end = -1;

    for (
        short *plhs = lhs_end - 1, *prhs = rhs_end - 1, *pres = res_end - 1;
        res_end >= result && (plhs >= lhs || prhs >= rhs);
        plhs--, prhs--, pres--)
    {
        short l_add = plhs >= lhs ? *plhs : 0;
        short r_add = prhs >= rhs ? *prhs : 0;
        *pres += l_add + r_add;
        if (*pres >= 10)
        {
            *(pres - 1) = *pres / 10;
            *pres %= 10;
        }
    }
    if (result[0])
    {
        return result;
    }
    else
    {
        short *result_part = calloc(size, sizeof(*result_part));
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