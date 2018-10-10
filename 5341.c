#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    printf("%c\n", c - 'A' + 'a');
    return 0;
}