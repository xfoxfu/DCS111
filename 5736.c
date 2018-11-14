#include <stdio.h>

#define DEBUG

#define MAX_SIZE 20000
#define MAX_OP 200000

long long safe_access(int *nums, int pos, int lbound, int rbound)
{
    if (pos < lbound || pos > rbound)
        printf("[WARNING] access outbound pos=%d", pos);
    return nums[pos];
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    long long nums[MAX_SIZE];
    int op_sig = 1;
    long long op_add = 0;
    nums[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int num;
        scanf("%d", &num);
        nums[i] = nums[i - 1] + num;
    }
    for (int i = 0; i < m; i++)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            op_sig *= -1;
            op_add *= -1;
            break;
        case 2:
        {
            int x;
            scanf("%d", &x);
            op_add += x;
            break;
        }
        case 3:
        {
            int l, r;
            scanf("%d%d", &l, &r);
            long long res = (nums[r] - nums[l - 1]) * op_sig + op_add * (r - l + 1);
            printf("%lld\n", res);
            break;
        }
        }
    }
}