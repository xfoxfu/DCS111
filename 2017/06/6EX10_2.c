#include <stdio.h>

int main()
{
    FILE* fin;
    FILE* fout;
    fin = fopen("1.txt", "r");
    fout = fopen("2.txt", "w");

    while(!feof(fin))
    {
        char buf;
        if(fscanf(fin, "%c", &buf) != EOF)
        {
            fprintf(fout, "%c", buf);
        }
        else
        {
            if(!feof(fin))
            {
                printf("I/O error!\n");
            }
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}