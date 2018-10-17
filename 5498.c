#include <stdio.h>

#define MAX_NUM 3

void swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
int partion(int *num, int p, int q)
{
    int pivot = num[p];
    int r = p;
    for (int i = p + 1; i <= q; i++)
    {
        if (num[i] < pivot)
        {
            swap(&num[i], &num[r++]);
            swap(&num[i], &num[r]);
        }
    }
    return r;
}
void quick_sort(int *num, int p, int q)
{
    if (p < q)
    {
        int r = partion(num, p, q);
        quick_sort(num, p, r - 1);
        quick_sort(num, r + 1, q);
    }
}
int main()
{
    int n = 3;
    int num[3];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    quick_sort(num, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", num[i]);
    }
    printf("\n");
    return 0;
}