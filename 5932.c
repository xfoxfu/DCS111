#define REDIR_IO_
#define DEBUG_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_arr(int *nums, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", nums[i]);
    putchar('\n');
}
void exchange(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
bool sorted(const int *nums, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}
#ifdef DEBUG
int iter_cnt = 0;
#endif
int bubble_sort(int *nums, int size, int time)
{
#ifdef DEBUG
    printf("<%d>\n", iter_cnt++);
#endif
    int exchanged = 0;
    for (int i = 0; i < size - 1 - time; i++)
    {
#ifdef DEBUG
        printf("[%d]", i);
#endif
        if (nums[i] > nums[i + 1])
        {
            exchange(nums + i, nums + i + 1);
            exchanged++;
        }
        print_arr(nums, size);
    }
    return exchanged;
}

int main()
{
#ifdef REDIR_IO
    freopen("5932.in", "r", stdin);
    freopen("5932.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        int *nums = calloc(t, sizeof(int));
        for (int j = 0; j < t; j++)
            scanf("%d", nums + j);
        int time = 0;
        while (bubble_sort(nums, t, time++))
        {
        }
    }
    return 0;
}