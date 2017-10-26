#include <stdio.h>

int main()
{
	char A[5];
	scanf("%s", A);
	for(int i=0;i<4;i++)
	{
		A[i] -= 32;
	}
	printf("%s\n", A);
	return 0;
}