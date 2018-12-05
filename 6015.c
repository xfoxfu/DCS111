int parseBinary(const char *const binaryString)
{
    int sum = 0;
    const char *pchr;
    for (pchr = binaryString; *pchr != '\0'; pchr++)
        ;
    pchr--;
    for (int base = 1; pchr >= binaryString; pchr--, base *= 2)
    {
        sum += (*pchr == '1') * base;
    }
    return sum;
}

#include <stdio.h>
#include <string.h>

int main()
{
    printf("%d\n", parseBinary("10001"));
    printf("%d\n", parseBinary("10101010101010"));
    printf("%d\n", parseBinary("111111111111"));

    return 0;
}
