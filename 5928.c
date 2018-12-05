#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        int count = 0;
        while (num != 0)
        {
            count += !!(num & 0x01);
            num >>= 1;
        }
        printf("%d", count);
    }
    return 0;
}