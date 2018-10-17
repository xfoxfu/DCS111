#include <stdio.h>

int main()
{
    int investment_monthly, interest_annual_precents;
    scanf("%d%d", &investment_monthly, &interest_annual_precents);
    float accumulated = investment_monthly;
    for (int i = 1; i <= 6; i++)
    {
        accumulated *= 1 + (float)interest_annual_precents / 12 / 100;
        if (i != 6)
            accumulated += investment_monthly;
    }
    printf("%.2f", accumulated);
    return 0;
}