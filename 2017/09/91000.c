#include <stdio.h>

#define MAX_NUM 100

int present(int *arr, int n, int num)
{
    int i; // loop var
    for (i = 0; i < n; i++)
        if (arr[i] == num)
            return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    int i; // loop var
    for (i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int numbers[MAX_NUM] = {0};
        int nextAlloc = 0;
        int j; // loop var
        for (j = 0; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            if (!present(numbers, nextAlloc, a))
            {
                numbers[nextAlloc] = a;
                nextAlloc++;
            }
        }
        for (j = 0; j < nextAlloc; j++)
        {
            printf("%d", numbers[j]);
            if (j != nextAlloc - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}