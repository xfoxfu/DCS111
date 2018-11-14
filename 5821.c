#define DEBUG_MAIN
#ifdef DEBUG_MAIN
#include <stdio.h>
#endif

int myStrlen(char a[])
{
    for (int i = 0;; i++)
    {
        if (a[i] == '\0')
            return i;
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int myStrcmp(char a[], char b[])
{
    for (int i = 0; i <= max(myStrlen(a), myStrlen(b)); i++)
    {
        if (a[i] - b[i])
        {
            return a[i] - b[i];
        }
    }
    return 0;
}

void myStrcpy(char des[], char src[])
{
    for (int i = 0; i <= myStrlen(src); i++)
    {
        des[i] = src[i];
    }
}

#ifdef DEBUG_MAIN
int main()
{
    char a[100], b[100], c[100];
    scanf("%s%s", a, b);
    myStrcpy(c, a);
    printf("%d %d\n%d\n%s", myStrlen(a), myStrlen(b), myStrcmp(a, b), c);
}
#endif