#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_array(int *array, int size)
{
    printf("%d", array[0]);
    for (int i = 1; i < size; i++)
    {
        printf(" %d", array[i]);
    }
    printf("\n");
}
bool present(int *arr, int size, int num)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == num)
            return true;
    return false;
}
void arrange(int n, int *previous, int previous_count)
{
    if (previous_count == n)
        print_array(previous, previous_count);
    else
    {
        int *remain = calloc(n - previous_count, sizeof(int));
        for (int i = 1, *pRemain = remain; i <= n; i++)
        {
            if (!present(previous, previous_count, i))
                *(pRemain++) = i;
        }
        int *previous_new = calloc(previous_count + 1, sizeof(int));
        memcpy(previous_new, previous, previous_count * sizeof(int));
        for (int i = 0; i < n - previous_count; i++)
        {
            previous_new[previous_count] = remain[i];
            arrange(n, previous_new, previous_count + 1);
        }
        free(previous_new);
        free(remain);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    arrange(n, NULL, 0);
    return 0;
}