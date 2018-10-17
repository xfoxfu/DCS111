#include <stdio.h>

int main()
{
    printf("%d ", sizeof(short));
    printf("%d ", sizeof(unsigned short));
    printf("%d ", sizeof(int));
    printf("%d ", sizeof(unsigned int));
    printf("%d ", sizeof(long));
    printf("%d ", sizeof(unsigned long));
    printf("%d ", sizeof(float));
    printf("%d ", sizeof(double));
    printf("%d\n", sizeof(long double));
    return 0;
}