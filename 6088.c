/*
第一行为一个整数t（0<t<10），表示测试用例个数。每个测试用例的第一行为两个整数n（1<n<=500000）和m（0<m<100000），
n表示小球的个数，m为指令条数，以下m行每行为一条指令。 
 */
#include <stdio.h>

#define MAX_N 500000

void run();

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        run();
    return 0;
}

typedef enum
{
    OP_LEFT = 1,
    OP_RIGHT,
} Op;

void swap(short *a, short *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
int get_pos(short *nums, int num)
{
    for (int i = 0;; i++)
    {
        if (nums[i] == num)
            return i;
    }
}
void run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    short nums[MAX_N];
    for (int i = 0; i < n; i++)
    {
        nums[i] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        int op, num, pos;
        scanf("%d%d%d", &op, &num, &pos);
        int num_pos = get_pos(nums, num);
        int pos_pos = get_pos(nums, pos);
        if (op == OP_LEFT)
        {
            if (num_pos < pos_pos)
            {
                for (int i = num_pos; i < pos_pos - 1; i++)
                    swap(nums + i, nums + i + 1);
            }
            else
            {
                for (int i = num_pos; i > pos_pos; i--)
                    swap(nums + i - 1, nums + i);
            }
        }
        else if (op == OP_RIGHT)
        {
            if (num_pos < pos_pos)
            {
                for (int i = num_pos; i < pos_pos; i++)
                    swap(nums + i, nums + i + 1);
            }
            else
            {
                for (int i = num_pos; i > pos_pos + 1; i--)
                    swap(nums + i - 1, nums + i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
}