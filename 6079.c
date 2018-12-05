#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STDIO_REDIR

#define SORT_FUNC(field, expr)                                \
    int comp_##field(const Student *a, const Student *b)      \
    {                                                         \
        return a->field != b->field ? (expr) : a->Id - b->Id; \
    }

typedef struct
{
    char Gender;
    char Name[7];
    int Id;
    int Score;
    int OriginalOrd;
} Student;
typedef enum
{
    OP_OT = 0,
    OP_SORT_G = 1,
    OP_SORT_N = 2,
    OP_SORT_I = 3,
    OP_SORT_S = 4,
    OP_Q = -1
} Op;

SORT_FUNC(Gender, a->Gender - b->Gender)
SORT_FUNC(Id, a->Id - b->Id)
SORT_FUNC(Score, b->Score - a->Score)
SORT_FUNC(Name, strncmp(a->Name, b->Name, 6));
SORT_FUNC(OriginalOrd, a->OriginalOrd - b->OriginalOrd);

void sort_table(Student *students, int n, Op op)
{
    int (*comp)(const Student *, const Student *);
    switch (op)
    {
    case OP_SORT_G:
        comp = comp_Gender;
        break;
    case OP_SORT_I:
        comp = comp_Id;
        break;
    case OP_SORT_N:
        comp = comp_Name;
        break;
    case OP_SORT_S:
        comp = comp_Score;
        break;
    case OP_OT:
        comp = comp_OriginalOrd;
        break;
    case OP_Q:
        comp = NULL;
        break;
    }
    qsort(students, n, sizeof(*students), (int (*)(const void *, const void *))comp);
}
void print_table(Student *students, int n)
{
    printf("Gender Name   Id       Score\n");
    for (int i = 0; i < n; i++)
        printf("%c      %-6s %8d %-5d\n", students[i].Gender, students[i].Name, students[i].Id, students[i].Score);
}
int main()
{
#ifdef STDIO_REDIR
    freopen("6079.in", "r", stdin);
    freopen("6079.out", "w", stdout);
#endif
    Student *students;
    int n;
    scanf("%d\n", &n);
    students = calloc(n, sizeof(*students));
    for (int i = 0; i < n; i++)
    {
        scanf("%c%s%d%d\n", &students[i].Gender, students[i].Name, &students[i].Id, &students[i].Score);
        students[i].OriginalOrd = i;
    }
    Op op;
    while (scanf("%d", &op) && op != OP_Q)
    {
        switch (op)
        {
        case OP_SORT_G:
        case OP_SORT_N:
        case OP_SORT_I:
        case OP_SORT_S:
        case OP_OT:
            sort_table(students, n, op);
            break;
        case OP_Q:
            break;
        }
        print_table(students, n);
        putchar('\n');
    }
    free(students);
    return 0;
}