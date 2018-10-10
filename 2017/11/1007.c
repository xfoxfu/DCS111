#include <stdio.h>

#define MAX_N 1000
#define MAX_M 100000

enum OP
{
    OPPOSITE = 1,
    ADD,
    PRINT_SUM
};
int main()
{
    freopen("1007.in", "r", stdin);
    int numbers[MAX_N];
    int num_count;
    int op_count;
    scanf("%d%d", &num_count, &op_count);
    if (num_count > MAX_N)
    {
        printf("numbers too much!");
        return 1;
    }
    if (op_count > MAX_M)
    {
        printf("operations too much!");
        return 1;
    }
    int i; // loop var
    for (i = 0; i < num_count; i++)
    {
        scanf("%d", &numbers[i]);
    }
    char op_signal = 1;
    long long op_add = 0;
    for (i = 0; i < op_count; i++)
    {
        enum OP op;
        scanf("%d", &op);
        switch (op)
        {
        case OPPOSITE:
        {
            op_signal *= -1;
            break;
        }
        case ADD:
        {
            int add;
            scanf("%d", &add);
            op_add += add * op_signal;
            break;
        }
        case PRINT_SUM:
        {
            int left, right;
            int j; // loop var
            scanf("%d%d", &left, &right);
            long long sum = 0;
            for (j = left - 1; j <= right - 1; j++)
            {
                sum += numbers[j] + op_add;
            }
            sum *= op_signal;
            printf("%lld\n", sum);
            break;
        }
        }
    }
    return 0;
}