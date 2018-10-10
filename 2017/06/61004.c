#include <stdio.h>

int main()
{
    const float fahrenheit = 72.0;
    const float celsius = (fahrenheit - 32) * (5 / 9.);
    printf("%.4f\n", celsius);
    return 0;
}