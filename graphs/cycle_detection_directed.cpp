#include <iostream>
#include <list>
#include <vector>
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

    bool dfs(int source, vector<int> &visited, vector<int> &current_route)
    {
        visited[source] = 1;
        current_route[source] = 1;

        for (auto node : l[source])
        {
            if (current_route[node])
                return true;
            else if (!visited[node])
            {
                bool hasACycle = dfs(node, visited, current_route);
                if (hasACycle)
                    return true;
            }
        }

        current_route[source] = 0;
        return false;
    }

    bool hasCycle()
    {
        vector<int> visited(V, 0);
        vector<int> current(V, 0);
        for (int i = 0; i < V; i++)
            if (!visited[i])
                if (dfs(i, visited, current))
                    return true;

        return false;
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 1, false);
    cout << g.hasCycle() << endl;
}
