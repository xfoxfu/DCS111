#include <stdio.h>

int main()
{
    // a 100 450.34 2147483648 4294967296 126.3455568
    char a;
    int b;
    float c;
    unsigned long d;
    unsigned long long e;
    long double f;
    double g;
    scanf("%c%d%f%lu%llu%lf", &a, &b, &c, &d, &e, &g);
    printf("%c %d %.2f %lu %llu %.7lf\n", a, b, c, d, e, g);
    return 0;
}