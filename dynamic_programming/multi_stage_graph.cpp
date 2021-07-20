#include <bits/stdc++.h>
using namespace std;

int multiStageGraph(int vertices, int **weight)
{
    int cost[vertices + 1], next_vertex[vertices + 1], min_cur_vertex_cost;

    // cost of sink
    cost[vertices] = 0;

    for (int i = vertices - 1; i >= 1; i--)
    {
        min_cur_vertex_cost = INT_MAX;
        for (int k = i + 1; k <= vertices; k++)
        {
            if ((weight[i][k]) && ((weight[i][k] + cost[k]) < min_cur_vertex_cost))
            {
                min_cur_vertex_cost = weight[i][k] + cost[k];
                next_vertex[i] = k;
            }
        }
        cost[i] = min_cur_vertex_cost;
    }

    vector<int> path(1, 1); // src (1)
    int last_visited_vertex = 1;
    while (true)
    {
        if (last_visited_vertex == vertices) // sink
            break;
        path.push_back(next_vertex[last_visited_vertex]);
        last_visited_vertex = path[path.size() - 1];
    }

    cout << "Path: ";
    for (auto x : path)
    {
        if (x != vertices)
            cout << x << " -> ";
        else
            cout << x << endl;
    }

    return cost[1];
}

int main()
{
    int vertices, stages;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    int **graph = new int *[vertices + 1];
    for (int i = 0; i <= vertices; i++)
        graph[i] = new int[vertices + 1];

    cout << "Enter the cost matrix weights\n";
    for (int u = 0; u <= vertices; u++)
    {
        for (int v = 0; v <= vertices; v++)
        {
            if (u == 0 || v == 0 || u == vertices)
                graph[u][v] = 0;
            else
            {
                cin >> graph[u][v];
            }
        }
    }

    int min_cost = multiStageGraph(vertices, graph);
    cout << "Minimum cost from source(" << 1 << ") to sink(" << vertices << "): " << min_cost << endl;
}
