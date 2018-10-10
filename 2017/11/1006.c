#include <stdio.h>
#include <math.h>

void do_case()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (fabs(c - a - b) < pow(10, -10))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}
int main()
{
    int cases;
    scanf("%d", &cases);
    int case_; // loop var
    for (case_ = 0; case_ < cases; case_++)
    {
        do_case();
    }
    return 0;
}