#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#ifdef DEBUG
#define DEBUG_IO
#define DEBUG_OUTPUT
#endif

#define TYPE int
#define SAFE_WARNING
#include "safe_iterator.c"

void print_arr(Array arr)
{
    Iterator begin = array_begin(&arr);
    Iterator end = array_end(&arr);
    printf("%d", *iter_value_s(begin));
    for (begin = iter_next(begin); iter_cmp(begin, end) <= 0; begin = iter_next(begin))
    {
        printf(" %d", *iter_value_s(begin));
    }
    printf("\n");
}

void merge_sort(Iterator start, Iterator end, Array arr)
{
    if (iter_cmp(start, end) >= 0)
        return;
    else
    {
        Iterator mid = iter_seek(start, iter_cmp(end, start) / 2); // (p + q) / 2;
        merge_sort(start, mid, arr);
        merge_sort(iter_next(mid), end, arr);
        // p .. r , r+1 .. q
        Array buffer = array_new(iter_cmp(end, start) + 1);
        for (
            Iterator cur_buf = array_begin(&buffer),
                     cur_left = start,
                     cur_right = iter_next(mid);
            iter_cmp(cur_buf, array_begin(&buffer)) <= iter_cmp(end, start);
            cur_buf = iter_next(cur_buf))
        {
            if (iter_cmp(cur_left, mid) <= 0 && iter_cmp(cur_right, end) <= 0)
            {
                if (*iter_value_s(cur_left) <= *iter_value_s(cur_right))
                {
                    *iter_value_s(cur_buf) = *iter_value_s(cur_left);
                    cur_left = iter_next(cur_left);
                }
                else
                {
                    *iter_value_s(cur_buf) = *iter_value_s(cur_right);
                    cur_right = iter_next(cur_right);
                }
            }
            else
            {
                if (iter_cmp(cur_left, mid) > 0)
                {
                    *iter_value_s(cur_buf) = *iter_value_s(cur_right);
                    cur_right = iter_next(cur_right);
                }
                else if (iter_cmp(cur_right, mid) > 0)
                {
                    *iter_value_s(cur_buf) = *iter_value_s(cur_left);
                    cur_left = iter_next(cur_left);
                }
            }
        }
        for (
            Iterator cur = array_begin(&buffer), cur_arr = start;
            iter_cmp(cur, array_begin(&buffer)) <= iter_cmp(end, start);
            cur = iter_next(cur), cur_arr = iter_next(cur_arr))
        {
            *iter_value_s(cur_arr) = *iter_value_s(cur);
        }
        array_free(buffer);
        print_arr(arr);
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
    Array nums = array_new(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", iter_value_s(array_at(&nums, i)));
    }
    merge_sort(array_begin(&nums), array_end(&nums), nums);
    array_free(nums);
    return 0;
}