#include <bits/stdc++.h>
using namespace std;

// O(N^3)
void allPairShortestPath(int vertices, int **adj_matrix)
{
    for (int k = 0; k < vertices; k++)
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
}

int main()
{
    int vertices, inf = 0;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    int **graph = new int *[vertices];
    for (int i = 0; i < vertices; i++)
        graph[i] = new int[vertices];

    cout << "Enter the cost matrix weights ";
    cout << "(for no edge, enter -1)\n";
    for (int u = 0; u < vertices; u++)
    {
        for (int v = 0; v < vertices; v++)
        {
            cin >> graph[u][v];
            if (graph[u][v] != -1)
                inf += graph[u][v];
        }
    }

    for (int u = 0; u < vertices; u++)
        for (int v = 0; v < vertices; v++)
            if (graph[u][v] == -1)
                graph[u][v] = inf;

    allPairShortestPath(vertices, graph);

    for (int u = 0; u < vertices; u++)
        for (int v = 0; v < vertices; v++)
            if (graph[u][v] != INT_MAX)
                cout << "Edge: [" << u << " - " << v << "], Cost: " << graph[u][v] << endl;
}