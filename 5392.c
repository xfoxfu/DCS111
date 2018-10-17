#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main()
{
    int n;
    scanf("%d", &n);
    bool first_printed = false;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a > 0)
        {
            if (first_printed)
            {
                printf(" ");
            }
            else
            {
                first_printed = true;
            }
            printf("%d", a);
        }
    }
    printf("\n");
    return 0;
}