#define LOCAL_MAIN
#ifdef LOCAL_MAIN
#include <stdio.h>

#define MAXLENGTH (1000 + 1)

int main()
{
    char s1[MAXLENGTH], s2[101];
    scanf("%s%s", s1, s2);
    int strMatch(const char *, const char *);
    printf("%d\n", strMatch(s1, s2));
    return 0;
}

#endif

#include <string.h>

int strMatch(const char *match, const char *pattern)
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