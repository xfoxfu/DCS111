#include <stdio.h>
#include <stdlib.h>

int hash(int num)
{
    if (num >= 0 && num < 60)
        return 0;
    if (num >= 60 && num < 75)
        return 1;
    if (num >= 75 && num < 85)
        return 2;
    if (num >= 85 && num < 95)
        return 3;
    if (num >= 95 && num <= 100)
        return 4;
    return 0; // !unreachable
}
int main()
{
    int judger_count;
    scanf("%d", &judger_count);
    int sum = 0, min, max;
    int score_count[5] = {0};
    for (int i = 0; i < judger_count; i++)
    {
        int score;
        scanf("%d", &score);
        if (i == 0 || score < min)
            min = score;
        if (i == 0 || score > max)
            max = score;
        sum += score;
        score_count[hash(score)]++;
    }
    sum -= min + max;
    printf("%.2f\n", sum / (judger_count - 2.0));
    for (int i = 0; i < 5; i++)
        printf("%d\n", score_count[i]);
    return 0;
}