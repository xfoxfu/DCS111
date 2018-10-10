#include <stdio.h>
// #include <math.h>

int main()
{
    char c;
    scanf("%c", &c);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 4; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}