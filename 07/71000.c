#include <stdio.h>

int main()
{
	char A[3];
	scanf("%s", A);
	for (int i = 0; i < 3; i++)
	{
		A[i] -= 32;
	}
	printf("%s\n", A);
	return 0;
}