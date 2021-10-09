#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>
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

    void bfs(int source)
    {
        queue<int> q;
        unordered_set<int> visited;

        q.push(source);
        visited.insert(source);
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            cout << top << " ";

            for (auto node : l[top])
            {
                if (visited.find(node) == visited.end())
                {
                    q.push(node);
                    visited.insert(node);
                }
            }
        }

        cout << endl;
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
    g.bfs(1);
}
