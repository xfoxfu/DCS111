#include <stdio.h>
#include <math.h>

int main()
{
    int score;
    scanf("%d", &score);
    if (score < 0 || score > 100)
        printf("Invalid");
    else if (score < 60)
        printf("Failed");
    else
        printf("%.1f", (score - 50) / 10.);
    printf("\n");
    return 0;
}