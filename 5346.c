#include <stdio.h>

int main()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j <= i)
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}