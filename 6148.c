void swap(unsigned long *a, unsigned long *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
double *min(double list[], int size)
{
    double *p_min = list;
    for (double *p = list + 1; p - list < size; p++)
    {
        if (*p < *p_min)
            p_min = p;
    }
    return p_min;
}
void selectionSort(double list[], int size)
{
    if (size == 0)
        return;
    double *p_min = min(list, size);
    swap((unsigned long *)p_min, (unsigned long *)list);
    selectionSort(list + 1, size - 1);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    double *nums = calloc(n, sizeof(double));
    for (int i = 0; i < n; i++)
        scanf("%lf", nums + i);
    selectionSort(nums, n);
    for (int i = 0; i < n; i++)
        printf("%lf ", *(nums + i));
    return 0;
}