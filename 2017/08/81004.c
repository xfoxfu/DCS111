#include <stdio.h>
#include <string.h>

int main()
{
    struct MaxScholarship
    {
        char name[21];
        int value;
    } maxScholarship;
    maxScholarship.value = 0;
    int sum = 0;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct Student
        {
            char name[21];
            int academicScore;
            int peerScore;
            char hasJob;
            char isFromWestProvinces;
            int papers;
            int scholarship;
        } stu;
        scanf("%s %d %d %c %c %d",
              stu.name,
              &stu.academicScore,
              &stu.peerScore,
              &stu.hasJob,
              &stu.isFromWestProvinces,
              &stu.papers);
        stu.scholarship = 0;
        if (stu.academicScore > 80 && stu.papers >= 1)
            stu.scholarship += 8000;
        if (stu.academicScore > 85 && stu.peerScore > 80)
            stu.scholarship += 4000;
        if (stu.academicScore > 90)
            stu.scholarship += 2000;
        if (stu.isFromWestProvinces == 'Y' && stu.academicScore > 85)
            stu.scholarship += 1000;
        if (stu.hasJob == 'Y' && stu.peerScore > 80)
            stu.scholarship += 850;

        if (stu.scholarship > maxScholarship.value)
        {
            strcpy(maxScholarship.name, stu.name);
            maxScholarship.value = stu.scholarship;
        }
        sum += stu.scholarship;
    }
    printf("%s\n%d\n%d\n", maxScholarship.name, maxScholarship.value, sum);
    return 0;
}