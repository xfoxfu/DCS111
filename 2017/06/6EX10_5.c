#include <stdio.h>

int main()
{
    int outputBuf[10] = {1,2,3,4,5,6,7,8,9,10};
    char filename[20];

    printf("Please input the filename: ");
    scanf("%s", filename);

    FILE* fout;
    if((fout = fopen(filename, "wb")) == NULL)
    {
        printf("OUTPUT error!\n");
    }
    else
    {
        fwrite(outputBuf, sizeof(int), 10, fout);
        fclose(fout);
    }
    return 0;
}