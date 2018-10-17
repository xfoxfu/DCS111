#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int is_valid = true;
    if ((a + b <= c) || (b + c <= a) || (a + c <= b))
        is_valid = false;
    if (is_valid)
    {
        printf("valid\n");
    }
    else
    {
        printf("invalid\n");
    }
    return 0;
}