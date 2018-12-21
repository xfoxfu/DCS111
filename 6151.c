void exchange(long int *a, long int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
int bubble_sort_basic(double *nums, int size, int time)
{
    int exchanged = 0;
    for (int i = 0; i < size - 1 - time; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            exchange((long int *)(nums + i), (long int *)(nums + i + 1));
            exchanged++;
        }
    }
    return exchanged;
}
void bubbleSort(double *nums, int size)
{
    int time = 0;
    int exchanged;
    do
    {
        exchanged = bubble_sort_basic(nums, size, time++);
    } while (exchanged != 0);
}