#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long sum = 0;
    long long sumSquare = 0;
    for (int i = 0; i < n; i++)
    {
        int score;
        scanf("%d", &score);
        sum += score;
        sumSquare += score * score;
    }
    double e = (double)sum / n;
    double d = (double)sumSquare / n - e * e;
    printf("%.2lf %.2lf\n", e, d);
    return 0;
}