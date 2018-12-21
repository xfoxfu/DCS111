#include <stdio.h>
#include <stdbool.h>

bool present(char *str, char chr)
{
    for (; *str != '\0'; str++)
    {
        if (*str == chr)
            return true;
    }
    return false;
}
void strip(char *str, char *filter, char *dest)
{
    for (; *str != '\0'; str++)
    {
        if (!present(filter, *str))
            *(dest++) = *str;
    }
    *dest = '\0';
}
int main()
{
    char input[100], filter[100];
    scanf("%s%s", input, filter);
    char output[100];
    strip(input, filter, output);
    printf("%s\n", output);
    return 0;
}