#include <stdio.h>

int main()
{
    int outputBuf[10] = {1,2,3,4,5,6,7,8,9,10};
    int inputBuf[10] = {0};

    FILE* fout;
    if((fout = fopen("1.dat", "wb")) == NULL)
    {
        printf("OUTPUT error!\n");
    }
    else
    {
        fwrite(outputBuf, sizeof(int), 10, fout);
        fclose(fout);
    }

    FILE* fin;
    if((fin = fopen("1.dat", "rb")) == NULL)
    {
        printf("INPUT error!\n");
    }
    else
    {
        for(int i=0;i<5;i++)                      
        {
                fread(&inputBuf[i], sizeof(int), 1, fin);   
                fseek(fin, sizeof(int), SEEK_CUR);   
        }
        for(int i=0;i<5;i++)
        {
            printf("%d ", inputBuf[i]);
        }
        fclose(fin);
    }

    return 0;
}