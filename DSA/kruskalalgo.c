#include <stdio.h>
#include <stdlib.h>

#define INF 9999999
#define MAX 20

int parent[MAX];

int find(int i)
{
    while (parent[i] != -1)
        i = parent[i];

    return i;
}

int unionSet(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }

    return 0;
}

int main()
{
    int n;
    int edges = 0;
    int minCost = 0;

    int cost[MAX][MAX];

    int i, j;
    int a, b, u, v;
    int min;

    printf("========================\n");
    printf("       KRUSKAL'S MST\n");
    printf("========================\n");

    printf("Enter the no of vertices: ");
    scanf("%d", &n);

    /* Initialize parent array */
    for (i = 0; i < n; i++)
    {
        parent[i] = -1;
    }

    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    /* Replace 0 with INF */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("========================\n");
    printf("Minimum Cost Spanning Tree:\n");

    /* MST contains n-1 edges */
    while (edges < n - 1)
    {
        min = INF;

        /* Find the minimum-cost edge */
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        /* Find roots */
        u = find(u);
        v = find(v);

        /* Add edge if it does not form a cycle */
        if (unionSet(u, v))
        {
            printf("%d -> %d = %d\n", a, b, min);
            minCost += min;
            edges++;
        }

        /* Remove selected edge */
        cost[a][b] = INF;
        cost[b][a] = INF;
    }

    printf("========================\n");
    printf("Minimum Cost = %d\n", minCost);
    printf("========================\n");

    return 0;
}