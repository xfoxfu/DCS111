#include <stdio.h>

#define NUMBERS 20
#define MIN 10
#define MAX 100

#define DEBUG_

int main()
{
    int count[MAX - MIN + 1] = {0};
    int i; // loop var
    for (i = 0; i < NUMBERS; i++)
    {
        int a;
        scanf("%d", &a);
#ifdef DEBUG
        printf("%d=%d\n", a, count[a - MIN]);
#endif
        if (!count[a - MIN])
        {
            printf("%d ", a);
        }
        count[a - MIN]++;
    }
    return 0;
}