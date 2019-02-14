#include <stdio.h>

void swap(int *a, int *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
int main()
{
    int arr[11] = {1, 4, 6, 9, 13, 16, 19, 28, 40, 100};
    int insert;
    // input
    scanf("%d", &insert);
    // handle
    arr[10] = insert;
    for (int i = 9; arr[i] > arr[i + 1] && i >= 0; i--)
        swap(arr + i, arr + i + 1);
    // output
    for (int i = 0; i <= 10; i++)
    {
        if (i != 0)
            putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
    return 0;
}