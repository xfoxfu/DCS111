#include <stdio.h>
#include <math.h>

int main()
{
	float x;
	scanf("%f", &x);
	float fx;
	if(x<-1) fx = x+1;
	else if(x<1) fx = x>=0 ? x : -x;
	else fx = log(x) / log(10);
	printf("%.2f\n", fx);
	return 0;
}