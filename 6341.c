#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exchange(char *a, char *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
int bubble_sort_basic(char *nums, int size, int time)
{
    int exchanged = 0;
    for (int i = 0; i < size - 1 - time; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            exchange(nums + i, nums + i + 1);
            exchanged++;
        }
    }
    return exchanged;
}
void bubble_sort(char *nums, int size)
{
    int time = 0;
    int exchanged;
    do
    {
        exchanged = bubble_sort_basic(nums, size, time++);
    } while (exchanged != 0);
}

int main()
{
    char str[101];
    char *ptail;
    for (ptail = str; (*ptail = getchar()) != '\n' && ptail - str <= 100; ptail++)
        NULL;
    bubble_sort(str, ptail - str);
    for (ptail = str; *ptail != '\n'; ptail++)
        putchar(*ptail);
    putchar('\n');
    return 0;
}
