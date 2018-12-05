int countLetters(const char *const str)
{
    int count = 0;
    for (const char *pchr = str; *pchr != '\0'; pchr++)
        count += (*pchr >= 'A') && (*pchr <= 'z');
    return count;
}

#include <stdio.h>
#include <string.h>

int main()
{
    printf("%d\n", countLetters("C++ and Java in 2008"));
    printf("%d\n", countLetters("cpp and Java in CS2010D"));

    return 0;
}
