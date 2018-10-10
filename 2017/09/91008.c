#include <stdio.h>

#define NUM 10
#define DEBUG_

void dump(int *numbers)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
int partion(int *A, int p, int r)
{
    const int pivot = A[r];
    int q = p - 1;
    int i; // loop var
    for (i = p; i <= r - 1; i++)
    {
        if (A[i] < pivot)
        {
            q++;
            if (q != i)
                swap(&A[q], &A[i]);
        }
#ifdef DEBUG
        dump(A);
#endif
    }
    q++;
    if (A[r] < A[q])
        swap(&A[r], &A[q]);
    return q;
}
void qsort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partion(A, p, r);
#ifdef DEBUG
        dump(A);
#endif
        qsort(A, p, q - 1);
        qsort(A, q + 1, r);
#ifdef DEBUG
        dump(A);
#endif
    }
}
int main()
{
    int numbers[NUM];
    int i; // loop var
    for (i = 0; i < NUM; i++)
    {
        int a;
        scanf("%d", &a);
        numbers[i] = a;
    }
#ifdef DEBUG
    dump(numbers);
#endif
    qsort(numbers, 0, NUM - 1);
    for (i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    return 0;
}