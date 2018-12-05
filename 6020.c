#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int *count(const char *const s)
{
    int *result = calloc(10, sizeof(int));
    for (const char *pchr = s; *pchr != '\0'; pchr++)
    {
        if (*pchr >= '0' && *pchr <= '9')
            result[*pchr - '0']++;
    }
    return result;
}

int main()
{
    int *counts = count("SSN is 343 32 4545 and ID is 434 34 4323");
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", i, counts[i]);
    printf("\n");
    free(counts);

    counts = count("My birthday is 2007-11-11.");
    for (int i = 0; i < 10; i++)
        printf("%d %d\n", i, counts[i]);
    ;
    free(counts);

    return 0;
}
