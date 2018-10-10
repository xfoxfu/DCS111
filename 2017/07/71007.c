#include <stdio.h>

int main()
{
	int year;
	scanf("%d", &year);
	int years_past = year - 2001;
	// 365 % 7 == 1
	int weekdays_past = (years_past + years_past / 4) % 7;
	printf("%d\n", (1 + weekdays_past) % 7);
	return 0;
}