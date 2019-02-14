#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100

bool has_route(bool routes[MAX_N][MAX_N], bool *visited, int n, int start, int end)
{
    if (start == end)
        return true;
    bool result = false;
    visited[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && routes[start][i])
        {
            result = result || has_route(routes, visited, n, i, end);
        }
    }
    return result;
}
int main()
{
    // input: users
    int n;
    scanf("%d", &n);
    // input: routes
    bool routes[MAX_N][MAX_N] = {};
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        routes[a][b] = true;
        routes[b][a] = true;
    }
    // query
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        bool visited[MAX_N] = {false};
        int a, b;
        scanf("%d%d", &a, &b);
        if (has_route(routes, visited, n, a, b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}