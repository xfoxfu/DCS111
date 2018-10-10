#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    float x, y;
    scanf("%d%d%d%f%f", &a, &b, &c, &x, &y);
    printf("%.3f\n", 1200. / (24 - 4 * 5));
    printf("%.3f\n", c * sqrt(a * a + b * b));
    printf("%.3f\n", log(log(pow(10, x) + y)));
    printf("%.3f\n", y + a % 5 * ((int)((x + y) / 2) % 4));
    return 0;
}