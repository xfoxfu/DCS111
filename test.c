#include <stdio.h>
#include <stdlib.h>

int main()
{
    short *a = calloc(5, sizeof(*a));
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    short *start = &a[0];
    short *end = &a[4];
    printf("%d", *(start + 1));
    return 0;
}