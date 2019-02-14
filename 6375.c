#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *nums, int p, int q)
{
    if (p >= q)
        return;
    else
    {
        int r = (p + q) / 2; // (q - p + 1) / 2 == 0 ? (p + q) / 2 : (p + q) / 2 + 1;
        merge_sort(nums, p, r);
        merge_sort(nums, r + 1, q);
        // p .. r , r+1 .. q
        int *buffer = calloc(q + 1, sizeof(int));
        for (int lp = p, lq = r + 1, curr = p; lp <= r || lq <= q;)
        {
            if (lp <= r && lq <= q)
            {
                if (nums[lp] <= nums[lq])
                {
                    buffer[curr++] = nums[lp++];
                }
                else
                {
                    buffer[curr++] = nums[lq++];
                }
            }
            else
            {
                if (lp > r)
                {
                    buffer[curr++] = nums[lq++];
                }
                else if (lq > q)
                {
                    buffer[curr++] = nums[lp++];
                }
            }
        }
        for (int i = p; i <= q; i++)
        {
            nums[i] = buffer[i];
        }
        free(buffer);
    }
}

int main(void)
{

    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n), i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    merge_sort(arr, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}
