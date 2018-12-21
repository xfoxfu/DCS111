#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int switched_off = 0;
    bool is_off[100] = {false};
    int light_id = 0;
    while (switched_off < n)
    {
        for (int i = 0; i < m - 1;)
        {
            // printf("[DEBUG] tested %d is %d", light_id, is_off[light_id]);
            if (is_off[light_id++] == false)
                i++;
            if (light_id >= n)
                light_id %= n;
        }
        while (is_off[light_id++] == true)
        {
            if (light_id >= n)
                light_id %= n;
        }
        is_off[--light_id] = true;
        switched_off++;
        printf("%d\n", light_id + 1);
    }
    return 0;
}