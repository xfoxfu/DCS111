#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        if (n % 3)
            printf("dalao win!\n");
        else
            printf("xinpang win!\n");
    }
    return 0;
}