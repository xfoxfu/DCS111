#include <math.h>
#include <stdio.h>

int smallestElement(int *list, int size)
{
    int *min = list;
    for (int *p = list + 1; p < list + size; p++)
        if (*p < *min)
            min = p;
    return *min;
}

int main()
{
    int list1[] = {1, 2, 3};
    int list2[] = {1, 3, 2};
    int list3[] = {2, 1, 3};
    int list4[] = {2, 3, 1};
    int list5[] = {3, 1, 2};
    int list6[] = {3, 0, 1};

    printf("The min is %d\n", smallestElement(list1, 3));
    printf("The min is %d\n", smallestElement(list2, 3));
    printf("The min is %d\n", smallestElement(list3, 3));
    printf("The min is %d\n", smallestElement(list4, 3));
    printf("The min is %d\n", smallestElement(list5, 3));
    printf("The min is %d\n", smallestElement(list6, 3));

    return 0;
}
