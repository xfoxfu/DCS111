#include <stdio.h>

const int queue_max_size = 40;

typedef struct
{
    int nums[40];
    int head_pos;
    int tail_pos;
} Queue;
void handle()
{
    int cards;
    scanf("%d", &cards);
    // initialize queue
    Queue queue;
    queue.head_pos = 0;
    queue.tail_pos = 0;
    for (int i = 0; i < cards; i++)
        queue.nums[i] = i + 1;
    queue.tail_pos = cards;
    // perform operation
    while (queue.tail_pos > queue.head_pos ? (queue.tail_pos - queue.head_pos > 1) : (queue.tail_pos + queue_max_size - queue.head_pos > 1))
    {
        queue.head_pos += 2;
        printf("%d ", queue.nums[queue.head_pos - 2]);
        queue.nums[queue.tail_pos++] = queue.nums[queue.head_pos - 1];
        if (queue.head_pos >= queue_max_size)
            queue.head_pos %= queue_max_size;
        if (queue.tail_pos >= queue_max_size)
            queue.tail_pos %= queue_max_size;
    }
    printf("%d\n", queue.nums[queue.head_pos]);
}
int main()
{
    int cases;
    scanf("%d", &cases);
    for (int t = 0; t < cases; t++)
    {
        handle();
    }
    return 0;
}