struct point
{
    int x;
    int y;
};

int cmp(struct point *a, struct point *b)
{
    if (a->x != b->x)
        return a->x - b->x;
    else
        return a->y - b->y;
}
void swap_int(int *a, int *b)
{
    if (*a != *b)
    {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
void swap(struct point *a, struct point *b)
{
    if (a->x != b->x)
        swap_int(&a->x, &b->x);
    if (a->y != b->y)
        swap_int(&a->y, &b->y);
}
int partion(struct point *num, int p, int q)
{
    struct point pivot = num[p];
    int r = p;
    for (int i = p + 1; i <= q; i++)
    {
        if (cmp(&num[i], &pivot) < 0)
        {
            swap(&num[i], &num[r++]);
            swap(&num[i], &num[r]);
        }
    }
    return r;
}
void quick_sort(struct point *num, int p, int q)
{
    if (p < q)
    {
        int r = partion(num, p, q);
        quick_sort(num, p, r - 1);
        quick_sort(num, r + 1, q);
    }
}

void point_sort(struct point a[], int n)
{
    quick_sort(a, 0, n - 1);
}