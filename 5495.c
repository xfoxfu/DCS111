#include <stdio.h>
#include <math.h>

int main()
{
    float x;
    scanf("%f", &x);
    if (x < -1)
        printf("%.2f", x + 1);
    else if (x > 1)
        printf("%.2f", log10(x));
    else if (x >= 0)
        printf("%.2f", x);
    else
        printf("%.2f", -x);
    printf("\n");
    return 0;
}