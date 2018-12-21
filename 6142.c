#include <stdio.h>
#include <stdbool.h>

const int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap(int year)
{
    if (year % 4) // != 0
        return false;
    else
    {
        if (year % 100) // != 0
            return true;
        else
        {
            if (year % 400) // != 0
                return false;
            else
                return true;
        }
    }
}
int main()
{
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
    int days_from_begin = 0;
    for (int i = 0; i < month - 1; i++)
        days_from_begin += days_of_month[i];
    if (is_leap(year) && month > 2)
        days_from_begin++;
    days_from_begin += day;
    printf("%d\n", days_from_begin);
    return 0;
}