#include <stdio.h>
#include <stdbool.h>

void move(int n, int src, int target)
{
    if (n == 0)
        return;
    move(n - 1, src, 6 - src - target);
    printf("%d%d\n", src, target);
    move(n - 1, 6 - src - target, target);
}
int main()
{
    int n;
    scanf("%d", &n);
    move(n, 1, 3);
    return 0;
}