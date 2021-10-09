#include <iostream>
#include <list>
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

    void dfsRecursion(int source, int visited[])
    {
        cout << source << " ";
        visited[source] = 1;
        for (auto node : l[source])
        {
            if (!visited[node])
                dfsRecursion(node, visited);
        }
    }

    void dfs(int source)
    {
        int visited[V] = {0};
        dfsRecursion(source, visited);
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.dfs(1);
}
