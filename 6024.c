#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *doubleCapacity(int *list, int size)
{
    int *res = calloc(size * 2, sizeof(int));
    memcpy(res, list, size * sizeof(int));
    return res;
}

int main()
{
    int list[100];
    for (int i = 0; i < 100; i++)
        *(list + i) = i;
    int *newlist = doubleCapacity(list, 100);
    for (int i = 0; i < 2 * 100; i++)
        printf("%d ", newlist[i]);
    free(newlist);
    return 0;
}
