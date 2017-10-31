#include <stdio.h>

#define MIN 0
#define MAX 9

int main()
{
    int t;
    scanf("%d", &t);
    int i; // loop var
    for (i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int count[MAX - MIN + 1] = {0};
        int j; // loop var
        for (j = 0; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            count[a - MIN]++;
        }
        for (j = MIN; j <= MAX; j++)
            if (count[j])
                printf("%d %d\n", j, count[j]);
    }
    return 0;
}