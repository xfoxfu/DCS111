#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d", &a, &b, &c);
	printf(a+b>c && b+c>a && a+c>b ? "Yes\n" : "No\n");
	return 0;
}