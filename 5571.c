#include <stdio.h>

int main()
{
    char presents[20][100];
    int present_top_next = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int action;
        scanf("%d", &action);
        if (action == 1)
        {
            scanf("%s", presents[present_top_next++]);
        }
        else if (action == 2)
        {
            char name[20];
            scanf("%s", name);
            printf("%s %s\n", name, presents[--present_top_next]);
        }
    }
    return 0;
}