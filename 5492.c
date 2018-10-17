#include <stdio.h>
#include <stdbool.h>

bool exists(int number, int *exsited, int exist_count)
{
    for (int i = 0; i < exist_count; i++)
    {
        if (exsited[i] == number)
            return true;
    }
    return false;
}
void make_exist(int number, int *existed, int *exist_count)
{
    if (!exists(number, existed, *exist_count))
        existed[(*exist_count)++] = number;
}
void action()
{
    int existed[100];
    int exist_count = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (!exists(a, existed, exist_count))
        {
            if (i)
            {
                printf(" %d", a);
            }
            else
            {
                printf("%d", a);
            }
        }
        make_exist(a, existed, &exist_count);
    }
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        action();
    }
    return 0;
}