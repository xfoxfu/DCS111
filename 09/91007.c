#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int i; // loop var
    for (i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int fstMax, sndMax;
        int j; // loop var
        for (j = 0; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            if (j == 0 || a > sndMax)
            {
                sndMax = a;
                j == 0 ? fstMax = a : 0;
            }
            if (sndMax > fstMax)
            {
                fstMax ^= sndMax;
                sndMax ^= fstMax;
                fstMax ^= sndMax;
            }
        }
        printf("%d\n", sndMax);
    }
    return 0;
}