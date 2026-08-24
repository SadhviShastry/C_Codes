#include <limits.h>     // For INT_MAX
#include <stdbool.h>   // For bool, true, false
#include <stdio.h>     // For input/output functions

#define V 5             // Graph has 5 vertices (0, 1, 2, 3, 4)

// Function to find the vertex with the minimum weight
// from the set of vertices not yet included in MST
int minweight(int weight[], bool visited[])
{
    int min = INT_MAX;
    int min_index = -1;

    // Traverse through all vertices
    for (int v = 0; v < V; v++)
    {
        // Select the vertex with minimum weight which is not visited
        if (visited[v] == false && weight[v] < min)
        {
            min = weight[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed MST and its total cost
void printMST(int parent[], int graph[V][V])
{
    int totalCost = 0;

    printf("MST for the graph:\n");
    printf("Edge\tWeight\n");

    // Start from vertex 1, since parent[0] = -1
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);

        // Add edge weight to total cost
        totalCost += graph[i][parent[i]];
    }

    printf("Total cost of MST: %d\n", totalCost);
}

// Function to construct and print MST using Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];      // Stores the MST
    int weight[V];      // Minimum weight edge to connect a vertex
    bool visited[V];    // Tracks vertices included in MST

    // Initialize all weights as infinity and visited as false
    for (int i = 0; i < V; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }

    // Always include the first vertex in MST
    weight[0] = 0;
    parent[0] = -1;

    // Construct MST with V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick vertex with minimum weight
        int u = minweight(weight, visited);

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update weight and parent of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // If v is not visited, edge exists,
            // and edge weight is smaller than current weight
            if (graph[u][v] != 0 &&
                visited[v] == false &&
                graph[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main()
{
    // Adjacency Matrix representation of the graph
    int graph[V][V] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Run Prim's Algorithm
    primMST(graph);

    return 0;
}