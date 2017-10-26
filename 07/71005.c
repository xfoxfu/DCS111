#include <stdio.h>

int main()
{
	int score;
	scanf("%d", &score);
	if(score > 100 || score < 0)
	{
		printf("Invalid\n");
	}
	else if(score < 60)
	{
		printf("Failed\n");
	}
	else
	{
		printf("%.1f\n", (score - 50) / 10.);
	}
	return 0;
}