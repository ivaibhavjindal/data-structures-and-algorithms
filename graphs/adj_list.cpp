#include <iostream>
#include <list>

using namespace std;

class Graph
{
    // pointer to an array of lists
    list<int> *l;
    int V; // vertices
public:
    Graph(int v)
    {
        V = v;
        // array of lists of size V
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undirected = true)
    {
        l[i].push_back(j);
        if (undirected)
            l[j].push_back(i);
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " --> ";
            for (auto node : l[i])
                cout << node << ", ";
            cout << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.printAdjList();
}