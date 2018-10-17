#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    bool form = true;
    if ((a + b <= c) || (b + c <= a) || (a + c <= b))
        form = false;
    if (form)
        printf("Yes\n");
    else
        printf("No\n");
}