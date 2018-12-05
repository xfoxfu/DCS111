#include <stdio.h>
#include <string.h>

int indexOf(const char *pattern, const char *match)
{
    for (int pos = 0, pattern_pos = 0;
         match[pos] != '\0';
         pos++)
    {
        if (match[pos] == pattern[pattern_pos])
        {
            pattern_pos++;
            if (pattern[pattern_pos] == '\0')
                return pos - pattern_pos + 1;
        }
        else
        {
            if (pattern_pos != 0)
            {
                pos--;
                pattern_pos = 0;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d%*c", &t);
    while (t--)
    {
        // Prompt the user to enter a string
        printf("Enter the first string: ");
        char s1[80];
        fgets(s1, 80, stdin);

        // Prompt the user to enter a string
        printf("Enter the second string: ");
        char s2[80];
        fgets(s2, 80, stdin);

        printf("%d\n", indexOf(s1, s2));
    }
    return 0;
}
