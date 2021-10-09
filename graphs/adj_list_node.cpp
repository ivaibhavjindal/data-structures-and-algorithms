#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Node
{
    string name;

public:
    list<string> nbrs;
    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
            m[city] = new Node(city);
    }

    void addEdge(string city1, string city2, bool undirected = true)
    {
        m[city1]->nbrs.push_back(city2);
        if (undirected)
            m[city2]->nbrs.push_back(city1);
    }

    void printAdjList()
    {
        for (auto p : m)
        {
            cout << p.first << " --> ";
            for (auto city : p.second->nbrs)
                cout << city << ", ";
            cout << endl;
        }
    }
};

int main()
{
    vector<string> cities = {"A", "B", "C", "D", "E"};
    Graph g(cities);
    g.addEdge("A", "B");
    g.addEdge("A", "D");
    g.addEdge("B", "C");
    g.addEdge("B", "D");
    g.addEdge("B", "E");
    g.addEdge("D", "E");
    g.addEdge("C", "A");
    g.printAdjList();
}