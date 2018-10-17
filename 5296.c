#include <stdio.h>

// *******************************************************************
// Celsius program
// This program output the Celsius temperature
// corresponding to a given Fahrenheit temperature
// *******************************************************************

int main()
{
    const float fahrenheit = 72.0;
    float celsius = (fahrenheit - 32) * (5. / 9);
    printf("%.4f\n", celsius);
    return 0;
}
