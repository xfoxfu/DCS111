#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *doubleCapacity(int *list, int size, int addSize)
{
    int *new_arr = malloc(sizeof(int) * (size + addSize));
    memcpy(new_arr, list, sizeof(int) * size);
    for (int *ptr = new_arr + size; ptr <= new_arr + (size + addSize - 1); ptr++)
        *ptr = 0;
    return new_arr;
}

int main()
{
    int *doubleCapacity(int *list, int size, int addSize);
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int a[10];
    int i = 0;
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    int *newlist = doubleCapacity(a, m, n);

    for (i = 0; i < (m + n); i++)
        printf("%d ", newlist[i]);
    free(newlist);
    return 0;
}