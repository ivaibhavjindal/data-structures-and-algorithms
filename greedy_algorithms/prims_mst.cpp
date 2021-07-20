#include <bits/stdc++.h>
using namespace std;

/*
prims(weight, n) {
    visited[0...n] = false
    dist[0...n] = inf
    neighbour[0...n] = -1

    dist[0] = 0;
    for i = 0 to n-1 do {
        u, min_dist = inf
        for v = 0 to n do {
            if(visited[v] = false and dist[v] < min_dist) {
                min_dist = dist[v]
                u = v
            }
        } 

        visited[u] = true
        for v = 0 to n do {
            if(visited[v] = false and dist[v] > weight[u][v]) {
                dist[v] = weight[u][v]
                neighbour[v] = u
            }
        }
    }
}
*/

// O(N^2)
void primsMst(int **weight, int n) 
{   
    bool visited[n] = {false};
    vector <int> neighbour(n, -1); // neighbour[i] = x => edge b/w x and i
    vector <int> distance(n, INT_MAX); // distance[i] = x => cost of edge (neighbour[i] - i)
 
    distance[0] = 0; 

    // MST will have n-1 edges
    for(int i = 0; i < n-1; i++) {
        // initialisation
        int u = -1, d = INT_MAX;

        // find vertex(u) not yet visited and having minimum distance 
        for(int v = 0; v < n; v++) {
            if(!visited[v] && distance[v] < d) {
                d = distance[v];
                u = v;
            }
        }
        // visit u
        visited[u] = true;

        for(int v = 0; v < n; v++) {
            // find shortest edge from u which is not visited and update its neighbour
            if(!visited[v] && weight[u][v] && (distance[v] > weight[u][v])) {
                distance[v] = weight[u][v];
                neighbour[v] = u;
            }
        }
    }
    
    // print minimum spanning tree
    int min_cost = 0;
    cout << "MST edges are:\n";
    for(int v = 1; v < n; v++) {
        cout << neighbour[v] << " - " << v << ": " << distance[v] << endl; 
        min_cost += distance[v]; // update min_cost
    }
    cout << "Total minimum cost: " << min_cost << endl;

}

int main()
{
    int vertices;
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

    primsMst(cost, vertices);   
}