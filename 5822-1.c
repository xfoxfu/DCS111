#include <stdio.h>

#define MAX_ARR 100
#define DEBUG

void print_arr(int nums[MAX_ARR], int p, int q)
{
    printf("%d", nums[p++]);
    for (; p <= q; p++)
    {
        printf(" %d", nums[p]);
    }
    printf("\n");
}
void merge_sort(int nums[MAX_ARR], int p, int q, int total)
{
    if (p >= q)
        return;
    else
    {
        int r = (p + q) / 2; // (q - p + 1) / 2 == 0 ? (p + q) / 2 : (p + q) / 2 + 1;
#ifdef DEBUG
        printf("[DEBUG] %d .. %d , %d .. %d\n", p, r, r + 1, q);
#endif
        merge_sort(nums, p, r, total);
        merge_sort(nums, r + 1, q, total);
        // p .. r , r+1 .. q
        int buffer[MAX_ARR] = {0};
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
        print_arr(nums, 0, total - 1);
    }
}
int main()
{
#ifdef DEBUG
    freopen("5822.in", "r", stdin);
    freopen("5822.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    int nums[MAX_ARR];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    merge_sort(nums, 0, n - 1, n);
    return 0;
}