#include <stdio.h>
#include <stdlib.h>

#define REDIR_IO

void swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
void print_array(int *array, int size)
{
    printf("%d", array[0]);
    for (int i = 1; i < size; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}
void select_sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int *pMin = array + i;
        for (int *p = pMin; p < array + size; p++)
        {
            if (*p < *pMin)
                pMin = p;
        }
        swap(array + i, pMin);
        print_array(array, size);
    }
}
void suite()
{
    int n;
    scanf("%d", &n);
    int *array = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }
    select_sort(array, n);
    free(array);
}
int main()
{
#ifdef REDIR_IO
    freopen("6023.out", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        suite();
    }
    return 0;
}