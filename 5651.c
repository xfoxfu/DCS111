#include <stdio.h>

void print_num(int num)
{
    for (int base = 64; base >= 1; base /= 2)
    {
        printf("%d", num / base % 2);
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    if (num >= 0)
    {
        printf("0");
        print_num(num);
    }
    else
    {
        printf("1");
        print_num(128 + num);
    }
    printf("\n");
    return 0;
}