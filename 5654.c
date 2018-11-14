#include <stdio.h>

void execute()
{
    int count[10] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        count[num]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (count[i])
            printf("%d %d\n", i, count[i]);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        execute();
    return 0;
}