#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undirected = true)
    {
        l[i].push_back(j);
        if (undirected)
            l[j].push_back(i);
    }

    void shortestDistanceBfs(int source)
    {
        queue<int> q;
        int visited[V] = {0};
        int distance[V] = {0};
        int parent[V];

        for (int i = 0; i < V; i++)
            parent[i] = -1;

        q.push(source);
        visited[source] = 1;
        parent[source] = source;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (auto v : l[f])
            {
                if (!visited[v])
                {
                    visited[v] = 1;
                    parent[v] = f;
                    distance[v] = distance[f] + 1;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            cout << "Distance to " << i << " is " << distance[i] << endl;
        }
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.shortestDistanceBfs(1);
}