// https://leetcode.com/problems/find-center-of-star-graph/

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

    int findCenter()
    {
        for (int i = 0; i < V; i++)
            if (l[i].size() == V - 1)
                return i + 1;

        return 0;
    }
};

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int v = edges.size() + 1;
        Graph g(v);
        for (auto edge : edges)
            g.addEdge(edge[0] - 1, edge[1] - 1);

        return g.findCenter();
    }
};