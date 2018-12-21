#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int p;
    int q;
    double num;
} Number;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
bool is_simplist(int p, int q)
{
    if (gcd(p, q) != 1)
        return false;
    else
        return true;
}
int cmp(const Number *a, const Number *b)
{
    return a->num < b->num ? -1 : 1;
}

void swap(Number *a, Number *b)
{
    // printf("[SWAP-BEFORE]a = %d/%d %lf\n", a->p, a->q, a->num);
    // printf("[SWAP-BEFORE]b = %d/%d %lf\n", b->p, b->q, b->num);
    Number tmp = *a;
    *a = *b;
    *b = tmp;
    // printf("[SWAP-AFTER ]a = %d/%d %lf\n", a->p, a->q, a->num);
    // printf("[SWAP-AFTER ]b = %d/%d %lf\n", b->p, b->q, b->num);
}
int partion(Number *num, int p, int q)
{
    double pivot_num = num[p].num;
    int r = p;
    for (int i = p + 1; i <= q; i++)
    {
        if (num[i].num < pivot_num)
        {
            swap(&num[i], &num[r++]);
            swap(&num[i], &num[r]);
        }
    }
    return r;
}
void quick_sort(Number *num, int p, int q)
{
    if (p < q)
    {
        int r = partion(num, p, q);
        quick_sort(num, p, r - 1);
        quick_sort(num, r + 1, q);
    }
}
Number nums[25600];
int main()
{
    int n;
    scanf("%d", &n);
    Number *nums_top = nums;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i <= j; i++)
        {
            if (is_simplist(i, j))
            {
                Number *curr = nums_top++;
                curr->num = (double)i / j;
                curr->p = i;
                curr->q = j;
            }
        }
    }
    // for (Number *pnum = nums; pnum < nums_top; pnum++)
    //     printf("[DEBUG]%d/%d %lf\n", pnum->p, pnum->q, pnum->num); // DEBUG
    quick_sort(nums, 0, nums_top - nums - 1);
    for (Number *pnum = nums; pnum < nums_top; pnum++)
        printf("%d/%d\n", pnum->p, pnum->q);
    // printf("%d/%d %lf\n", pnum->p, pnum->q, pnum->num);
    return 0;
}