#include <stdio.h>
#include <math.h>

int main()
{
    int investment;
    double interest_rate_percents;
    int years;
    scanf("%d %lf %d", &investment, &interest_rate_percents, &years);
    double accumulated = investment * pow((1 + interest_rate_percents * 0.01 / 12), years*12);
    printf("%.2lf\n", accumulated);
    return 0;
}