#include <stdio.h>

int main()
{
    int base_a = 3;
    int base_b = 5;
    int base_c = 7;
    int base = base_a * base_b * base_c;
    int mod_a, mod_b, mod_c;
    scanf("%d%d%d", &mod_a, &mod_b, &mod_c);
    int scale_a = mod_a;
    int scale_b = mod_b;
    int scale_c = mod_c;
    int result = (int)(base_b * base_c * scale_a * 2 +
                       base_a * base_c * scale_b +
                       base_a * base_b * scale_c) %
                 base;
    if (!result)
        result += base_a * base_b * base_c;
    printf("%d\n", result);
    return 0;
}