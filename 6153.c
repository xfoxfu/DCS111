#include <stdio.h>

int mod_count(int id, int count_person)
{
    int count = 0;
    for (int i = 1; i <= count_person; i++)
    {
        if (id % i == 0)
            count++;
    }
    return count;
}
int main()
{
    int count_light, count_person;
    scanf("%d%d", &count_light, &count_person);
    for (int i = 1; i <= count_light; i++)
    {
        if (mod_count(i, count_person) % 2) // == 1
            putchar('#');
        else
            putchar('O');
    }
    putchar('\n');
    return 0;
}