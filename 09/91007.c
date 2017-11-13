#include <stdio.h>

#define DEBUG_

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
        int fstMaxInit = 0, sndMaxInit = 0;
        int j; // loop var
        for (j = 0; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            if ((!fstMaxInit) || a > fstMax)
            {
                if (fstMaxInit)
                    sndMax = fstMax;
                fstMax = a;
                fstMaxInit = 1;
            }
            else if ((!sndMaxInit) || a > sndMax)
            {
                sndMax = a;
                sndMaxInit = 1;
            }
#ifdef DEBUG
            printf("DEBUG> %d %d\n", fstMax, sndMax);
#endif
        }
        if (sndMax > fstMax && sndMax != fstMax)
        {
            fstMax ^= sndMax;
            sndMax ^= fstMax;
            fstMax ^= sndMax;
        }
        printf("%d\n", sndMax);
    }
    return 0;
}