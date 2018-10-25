#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double e = 0;
    double e2 = 0;
    for (int i = 0; i < n; i++)
    {
        int score;
        scanf("%d", &score);
        e += score * (1. / n);
        e2 += (score * score) * (1. / n);
    }
    printf("%.2lf %.2lf", e, e2 - e * e);
    return 0;
}