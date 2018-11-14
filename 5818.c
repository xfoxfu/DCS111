#include <stdio.h>

#define LOCAL_MAIN

#include <string.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int ctoi(char a)
{
    return a - '0';
}
char itoc(int i)
{
    return i + '0';
}
void add(char lhs[], char rhs[], char res[])
{
    char res_pre[10];
    res_pre[max(strlen(lhs), strlen(rhs)) + 1] = '\0';
    for (int i = max(strlen(lhs), strlen(rhs)); i >= 0; i--)
    {
        res_pre[i] = '0';
    }
    for (
        int i_lhs = strlen(lhs) - 1, i_rhs = strlen(rhs) - 1, i_res = max(i_lhs, i_rhs) + 1;
        i_res >= 1;
        i_res--, i_lhs--, i_rhs--)
    {
        int l_add = i_lhs >= 0 ? ctoi(lhs[i_lhs]) : 0;
        int r_add = i_rhs >= 0 ? ctoi(rhs[i_rhs]) : 0;
        res_pre[i_res] = itoc(l_add + r_add + ctoi(res_pre[i_res]));
        if (ctoi(res_pre[i_res]) >= 10)
        {
            res_pre[i_res - 1] = '1';
            res_pre[i_res] = itoc(ctoi(res_pre[i_res]) % 10);
        }
    }
    if (ctoi(res_pre[0]))
    {
        strcpy(res, res_pre);
    }
    else
    {
        strcpy(res, res_pre + 1);
    }
}

#ifdef LOCAL_MAIN
int main()
{
    char lhs[8] = {}, rhs[8] = {}, sum[10] = {};
    scanf("%s %s", lhs, rhs);
    add(lhs, rhs, sum);
    printf("%s\n", sum);
    return 0;
}
#endif