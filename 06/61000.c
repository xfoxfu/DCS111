#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int A[1000];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}