#include <bits/stdc++.h>
using namespace std;

/*
sssp(src, weight, n) {
    visited[0...n] = false
    dist[0..n] = inf

    dist[src] = 0
    for i = 0 to n do {
        u, min_dist = inf
        
        for v = 0 to n do {
            if(visited[v] = false and dist[v] <= min_dist) {
                min_dist = dist[v]
                u = v
            }
        } 
    
        visited[u] = true
        for v = 0 to n do {
            if(visited[v] = false and dist[v] > dist[u] + weight[u][v])
                dist[v] = dist[u] + weight[u][v]
        }
    }
}
*/

// O(N^2)
void singleSourceShortestPath(int source, int **weight, int n) 
{
    bool visited[n] = {false};
    vector <int> distance(n, INT_MAX);
    
    distance[source] = 0;

    for(int i = 0; i < n; i++) {
        // initialisation
        int u = -1, d = INT_MAX;
        
        // find vertex(u) not yet visited and having minimum distance 
        for(int v = 0; v < n; v++) {
            if(!visited[v] && distance[v] <= d) {
                d = distance[v];
                u = v;
            }
        }
        // visit u
        visited[u] = true;

        // update distances to vertices having a shorter path through u
        for(int v = 0; v < n; v++) {
            if(!visited[v] && weight[u][v] && (distance[v] > distance[u] + weight[u][v]))
                distance[v] = distance[u] + weight[u][v];
        }
    }
    
    // print shortest paths (O(N))
    cout << "Shortest paths are:\n";
    for(int v = 0; v < n; v++)
        if(source != v)
            cout << source << " -> " << v << ": " << distance[v] << endl;

}

int main()
{
    int vertices, src;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // initialisation of cost matrix (adjacency matrix)
    int **cost;
    cost = new int *[vertices];
    for(int i = 0; i < vertices; i++)
        cost[i] = new int[vertices];

    cout << "Enter the cost matrix weights\n";
    for(int u = 0; u < vertices; u++)
        for(int v = 0; v < vertices; v++)
            cin >> cost[u][v];

    cout << "Enter the source vertex: "; 
    cin >> src;

    singleSourceShortestPath(src, cost, vertices);   
}