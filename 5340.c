#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    float delta = sqrt(b * b - 4 * a * c);
    printf("%.3f %.3f\n", (-b - delta) / (2 * a), (-b + delta) / (2 * a));
    return 0;
}