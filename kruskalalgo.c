#include <stdio.h>
#include <stdlib.h>

const int inf = 999999;

int p[9] = {0};

int applyfind(int i)
{
    while (p[i] != 0)
        i = p[i];

    return i;
}

int applyunion(int i, int j)
{
    if (i != j)
    {
        p[j] = i;
        return 1;
    }

    return 0;
}

int main()
{
    int n;
    int cost[9][9];
    int i, j;
    int a, b, u, v;
    int ne = 1;
    int mincost = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
            {
                cost[i][j] = inf;
            }
        }
    }

    printf("\nMinimum Cost Spanning Tree:\n");

    while (ne < n)
    {
        int min_val = inf;

        /* Find the minimum cost edge */
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (cost[i][j] < min_val)
                {
                    min_val = cost[i][j];

                    a = u = i;
                    b = v = j;
                }
            }
        }

        /* Find the parents of the vertices */
        u = applyfind(u);
        v = applyfind(v);

        /* Check whether adding this edge creates a cycle */
        if (applyunion(u, v) != 0)
        {
            printf("%d -> %d  Cost = %d\n", a, b, min_val);

            mincost += min_val;
            ne++;
        }

        /* Remove this edge from consideration */
        cost[a][b] = cost[b][a] = inf;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}