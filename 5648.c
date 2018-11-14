#include <stdio.h>

void swap_if(int *a, int *b)
{
    if (*a > *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
void execute()
{
    int n;
    scanf("%d", &n);
    int max_fst, max_snd;
    scanf("%d%d", &max_fst, &max_snd);
    swap_if(&max_snd, &max_fst);
    for (int i = 2; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        swap_if(&num, &max_snd);
        swap_if(&max_snd, &max_fst);
    }
    printf("%d\n", max_snd);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        execute();
    }
    return 0;
}