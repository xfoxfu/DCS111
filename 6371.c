#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100

void relax(int *pv, int nv)
{
    if (nv < *pv || *pv == -1)
        *pv = nv;
}
int extract_min(int U[], int n)
{
    int min = -1;
    for (int i = 0; i < n; i++)
        if (U[i] != -1 && (min == -1 || U[i] < U[min]))
            min = i;
    U[min] = -1;
    return min;
}
int shortest_path(int routes[MAX_N][MAX_N], int n, int start, int end)
{
    int known_path[MAX_N];
    for (int i = 0; i < n; i++)
    {
        known_path[i] = -1;
    }
    known_path[start] = 0;
    bool S[MAX_N] = {false};
    int U[MAX_N];
    for (int i = 0; i < n; i++)
    {
        U[i] = -1;
    }
    U[start] = 0;
    while ((start = extract_min(U, n)) != -1)
    {
        for (int i = 0; i < n; i++)
        {
            if (!S[i] && routes[start][i] >= 0)
            {
                relax(known_path + i, known_path[start] + routes[start][i]);
                U[i] = known_path[i];
            }
        }
        S[start] = true;
    }
    return known_path[end];
}
int main()
{
    freopen("6371.in", "r", stdin);
    freopen("6371.out", "w", stdout);
    // input: users
    int n;
    scanf("%d", &n);
    // input: routes
    int routes[MAX_N][MAX_N] = {};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            routes[i][j] = i == j ? 0 : -1;
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        routes[a][b] = w;
        routes[b][a] = w;
    }
    // query
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", shortest_path(routes, n, a, b));
    }
    return 0;
}