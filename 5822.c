#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 100
#define DEBUG

#ifdef DEBUG
#define DEBUG_IO
#define DEBUG_OUTPUT
#endif

void print_arr(int *start, int *end)
{
    printf("%d", *start);
    for (start++; start <= end; start++)
    {
        printf(" %d", *start);
    }
    printf("\n");
}

void merge_sort(int *start, int *end, int *arr_start, int *arr_end)
{
    if (start >= end)
        return;
    else
    {
        int *mid = start + (end - start) / 2; // (p + q) / 2;
        merge_sort(start, mid, arr_start, arr_end);
        merge_sort(mid + 1, end, arr_start, arr_end);
        // p .. r , r+1 .. q
        int *buffer = calloc(end - start + 1, sizeof(*buffer));
        for (
            int *cur_buf = buffer, *cur_left = start, *cur_right = mid + 1;
            cur_buf - buffer <= end - start;
            cur_buf++)
        {
            if (cur_left <= mid && cur_right <= end)
            {
                if (*cur_left <= *cur_right)
                {
                    *cur_buf = *cur_left++;
                }
                else
                {
                    *cur_buf = *cur_right++;
                }
            }
            else
            {
                if (cur_left > mid)
                {
                    *cur_buf = *cur_right++;
                }
                else if (cur_right > mid)
                {
                    *cur_buf = *cur_left++;
                }
            }
        }
        for (
            int *cur = buffer, *cur_arr = start;
            cur - buffer <= end - start;
            cur++, cur_arr++)
        {
            *cur_arr = *cur;
        }
        free(buffer);
        print_arr(arr_start, arr_end);
    }
}

int main()
{
#ifdef DEBUG_IO
    freopen("5822.in", "r", stdin);
    freopen("5822.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int *nums = calloc(n, sizeof *nums);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", nums + i);
    }
    merge_sort(nums, nums + n - 1, nums, nums + n - 1);
    free(nums);
    return 0;
}