#include <stdio.h>
#include <math.h>

#define bool int
#define true 1
#define false 0

int main()
{
    // accumulatedValue = investmentAmount * (1 + monthlyInterestRate) ^ (numberOfYear*12)
    int investment;
    float interest_annually;
    int years;
    scanf("%d%f%d", &investment, &interest_annually, &years);
    printf("%.2f\n", investment * pow((1 + interest_annually / 12 / 100), years * 12));
    return 0;
}