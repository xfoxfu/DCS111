#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

char s0[20];
char *prefix(const char *const s1, const char *const s2)
{
    const char *ps1, *ps2;
    for (ps1 = s1, ps2 = s2; *ps1 == *ps2; ps1++, ps2++)
        ;
    memcpy(s0, s1, sizeof(char) * (ps1 - s1));
    s0[ps1 - s1] = '\0';
    return s0;
}

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[] = "distance";
    char s2[] = "disjoint";
    puts(prefix(s1, s2));

    char *s3 = "distance";
    char *s4 = "";
    printf(":%s:\n", prefix(s3, s4));

    char *s5 = "distance";
    char *s6 = "dist";
    puts(prefix(s5, s6));
}
