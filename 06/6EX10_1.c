#include <stdio.h>

int main()
{
    FILE* fin;
    FILE* fout;
    fin = fopen("EX10_1.txt", "r");
    fout = fopen("result.txt", "w");

    int a;
    double b;
    char c;
    fscanf(fin, "%d %lf %c", &a, &b, &c);
    printf("%d %lf %c", a, b, c);
    fprintf(fout, "The answer is: %lf", a * b);

    fclose(fin);
    fclose(fout);
    return 0;
}