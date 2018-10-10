#include <stdio.h>

int main()
{
    FILE* fin;
    FILE* fout;
    fin = fopen("1.txt", "r");
    fout = fopen("2.txt", "w");

    char buf;
    while((buf = fgetc(fin)) != EOF && !feof(fin))
    {
        fputc(buf, fout);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}