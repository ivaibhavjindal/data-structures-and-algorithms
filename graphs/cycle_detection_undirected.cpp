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

    bool dfs(int source, int visited[], int parent)
    {
        visited[source] = 1;
        for (auto node : l[source])
        {
            if (!visited[node])
            {
                bool hasACycle = dfs(node, visited, source);
                if (hasACycle)
                    return true;
            }
            else if (node != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool hasCycle()
    {
        int visited[V] = {0};
        return dfs(0, visited, -1);
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    // g.addEdge(2, 0);
    cout << g.hasCycle() << endl;
}
