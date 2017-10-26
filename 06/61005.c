#include <stdio.h>

#define MONTHS 6

int main()
{
    int money_saved, interest_rate_percents;
    double account_balance = 0;
    scanf("%d%d", &money_saved, &interest_rate_percents);
    double interest_rate_monthly = interest_rate_percents * 0.01 / 12;
    for(int i = 0;i<MONTHS;i++)
    {
        account_balance = (money_saved + account_balance) * (1 + interest_rate_monthly);
    }
    printf("%.2lf\n", account_balance);
    return 0;
}