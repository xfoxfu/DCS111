#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 101
#define ARR_MAX 1000

int max(int a, int b)
{
    return a > b ? a : b;
}
void swap(char *a, char *b)
{
    if (strcmp(a, b) != 0)
    {
        char *tmp = calloc(max(strlen(a), strlen(b)) + 1, sizeof(char));
        strcpy(tmp, a);
        strcpy(a, b);
        strcpy(b, tmp);
        free(tmp);
    }
}
int partion(char num[][MAX_SIZE], int p, int q)
{
    int r = p;
    for (int i = p + 1; i <= q; i++)
    {
        if (strcmp(num[i], num[r]) < 0)
        {
            swap(num[i], num[r++]);
            swap(num[i], num[r]);
        }
    }
    return r;
}
void quick_sort(char num[][MAX_SIZE], int p, int q)
{
    if (p < q)
    {
        int r = partion(num, p, q);
        quick_sort(num, p, r - 1);
        quick_sort(num, r + 1, q);
    }
}

int cmp(const char *a, const char *b)
{
    return strcmp(a, b);
}
int main()
{
    int n;
    scanf("%d", &n);
    char strs[ARR_MAX][MAX_SIZE];
    for (int i = 0; i < n; i++)
        scanf("%s", strs[i]);
    // qsort(strs, n, sizeof(char[MAX_SIZE]), (int (*)(const void *, const void *))cmp);
    quick_sort(strs, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%s\n", strs[i]);
    return 0;
}
