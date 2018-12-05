#define DEBUG
#ifdef DEBUG
#define DEBUG_OUTPUT
#define DEBUG_IOREDIR
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point
{
    int x;
    int y;
} Point;
typedef struct Map
{
    int size;
    char **map;
    Point player_pos;
    bool locked;
} Map;

void print_map(Map *map)
{
    for (int i = -1; i <= map->size; i++)
    {
        for (int j = -1; j <= map->size; j++)
        {
            if (i == map->player_pos.x && j == map->player_pos.y)
                putchar('A');
            else if (!(i < 0 || i >= map->size || j < 0 || j >= map->size))
                putchar(map->map[i][j]);
            else
                putchar('*');
        }
        putchar('\n');
    }
}

void move(Map *map, int x, int y)
{
    map->player_pos.x = x;
    map->player_pos.y = y;
}

// @return dies
bool try_move_to(Map *map, int x, int y)
{
    if (map->locked)
    {
        map->locked = false;
        return false;
    }
    else if (x < 0)
        x = map->size - 1;
    else if (x >= map->size)
        x = 0;
    else if (y < 0)
        y = map->size - 1;
    else if (y >= map->size)
        y = 0;
    switch (map->map[x][y])
    {
    case '#':
        break;
    case '$':
        return true;
    case '@':
        map->locked = true;
    default:
        move(map, x, y);
    }
    return false;
}

bool map_move(Map *map, char move)
{
    /*
    # 墙
    会阻挡A的移动，假设A上方有#，而又尝试向上移动，则A的位置不变，输出原地图
    @ 水
    当A移动到@，其失去一次移动机会(即下一次移动尝试不会移动成功)
    输出时，在此处输出A；但A离开后，此处还会是@ (即重叠时输出A)
    $ 火
    当A移动到$，A死亡，不输出地图，输出Game Over!并结束程序
    */
    int x = map->player_pos.x;
    int y = map->player_pos.y;
    switch (move)
    {
    case 'w':
        x = map->player_pos.x - 1;
        y = map->player_pos.y;
        break;
    case 'a':
        x = map->player_pos.x;
        y = map->player_pos.y - 1;
        break;
    case 's':
        x = map->player_pos.x + 1;
        y = map->player_pos.y;
        break;
    case 'd':
        x = map->player_pos.x;
        y = map->player_pos.y + 1;
        break;
    default:
        return false;
    }
    bool result = try_move_to(map, x, y);
    if (!result)
        print_map(map);
    else
        printf("Game Over!\n");
    return result;
}

void map_free(Map *map)
{
    for (int i = 0; i < map->size; i++)
        free(map->map[i]);
    free(map->map);
}

int main()
{
#ifdef DEBUG_IOREDIR
    freopen("5922.in", "r", stdin);
    freopen("5922.out", "w", stdout);
#endif
    Map map;
    map.locked = false;
    scanf("%d\n", &map.size);
    map.map = calloc(map.size, sizeof(char *));
    for (int i = -1; i <= map.size; i++)
    {
        if (i >= 0 && i < map.size)
            map.map[i] = calloc(map.size, sizeof(char));
        for (int j = -1; j <= map.size + 1; j++)
        {
            char chr = getchar();
            if (chr == 'A')
            {
                map.player_pos.x = i;
                map.player_pos.y = j;
                chr = ' ';
            }
            if (i >= 0 && i < map.size && j >= 0 && j < map.size)
                map.map[i][j] = chr;
        }
    }
    char op;
    while ((op = getchar()) != EOF && !map_move(&map, op))
    {
    }
    map_free(&map);
    return 0;
}