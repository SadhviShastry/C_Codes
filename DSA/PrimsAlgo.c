// C Program to Implement Prim's Algorithm

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 20

// Function to find the vertex with the minimum weight value
// from the set of vertices not yet included in MST
int minweight(int weight[], bool visited[], int n)
{
    int min = INT_MAX;
    int min_index = -1;

    // Traverse through all vertices
    for (int v = 0; v < n; v++)
    {
        // Select the vertex with minimum weight
        // which is not visited yet
        if (visited[v] == false && weight[v] < min)
        {
            min = weight[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST and its total cost
void printMST(int parent[], int graph[MAX][MAX], int n)
{
    int totalCost = 0;

    printf("Minimum Spanning Tree:\n");
    printf("Edge\tWeight\n");

    // Start from vertex 1,
    // since parent[0] = -1 (root of MST)
    for (int i = 1; i < n; i++)
    {
        // Print edge between parent[i] and i
        printf("%d - %d\t%d\n",
               parent[i], i, graph[i][parent[i]]);

        // Add edge weight to total cost
        totalCost += graph[i][parent[i]];
    }

    // Print total cost of Minimum Spanning Tree
    printf("Total cost of MST: %d\n", totalCost);
}

// Function to construct and print MST using Prim's Algorithm
// Graph is represented by adjacency matrix
void primMST(int graph[MAX][MAX], int n)
{
    int parent[MAX];
    int weight[MAX];
    bool visited[MAX];

    // Initialize all weights as "infinite"
    // and visited[] as false
    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    // Always include the first vertex in MST
    weight[0] = 0;

    // Root of MST has no parent
    parent[0] = -1;

    // Construct MST with n-1 edges
    for (int count = 0; count < n - 1; count++)
    {
        // Pick vertex with minimum weight edge
        // not yet included in MST
        int u = minweight(weight, visited, n);

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update weight[] and parent[] of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            // If v is not visited, u-v edge exists,
            // and its weight is smaller than current weight[v]
            if (graph[u][v] &&
                visited[v] == false &&
                graph[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, n);
}

int main()
{
    int n;
    int graph[MAX][MAX];

    printf("========================\n");
    printf("        PRIM'S MST\n");
    printf("========================\n");

    printf("Enter the no of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("========================\n");

    // Run Prim's Algorithm
    primMST(graph, n);

    printf("========================\n");

    return 0;
}