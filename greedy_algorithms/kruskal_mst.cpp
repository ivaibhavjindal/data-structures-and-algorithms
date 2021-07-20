#include <bits/stdc++.h>
using namespace std;

void minHeapify(vector<pair<int, pair<int, int>>> &heap, int i) {
	int left_child_ind = 2*i;
	int right_child_ind = 2*i + 1;
	int small = i;

	if(left_child_ind < heap.size() && heap[left_child_ind].first < heap[small].first) 
		small = left_child_ind;

	if(right_child_ind < heap.size() && heap[right_child_ind].first < heap[small].first) 
		small = right_child_ind;

	if(small != i) {
		swap(heap[small], heap[i]);
		minHeapify(heap, small);
	}	
}

void buildHeap(vector<pair<int, pair<int, int>>> &heap) {
	int n = heap.size();
	for(int i = n/2; i >= 1; i--)
		minHeapify(heap, i);
}

int find(int vertex, int parent[]) {
	while(parent[vertex] > 0)
		vertex = parent[vertex];
	return vertex;
}	

void Union(int vertex1, int vertex2, int parent[]) {
	parent[vertex2] = vertex1;
}


int kruskal(vector<pair<int, pair<int, int>>> &E, int **cost, int vertices) {
	vector<pair<int, int>> mst;	
	buildHeap(E);
	
	int par[vertices + 1]; 
	for(int i = 0; i <= vertices; i++)
		par[i] = -1;

	int min_cost = 0;
	while(mst.size() < vertices-1 && E[1].first != INT_MAX) {

		int u = E[1].second.first;
		int v = E[1].second.second;

		E[1].first = INT_MAX;
		buildHeap(E);

		int j = find(u, par);
		int k = find(v, par);

		if(j != k) {
			mst.push_back(make_pair(u, v));
			min_cost += cost[u][v];
			Union(j, k, par);
		}
	}

	cout << "Minimum spanning tree\n";
	for(auto x: mst) {
		cout << x.first << " -> " << x.second << ": " << cost[x.first][x.second] << endl;
	}

	return min_cost;

}


int main()
{
	int n;
	cout << "Enter number of vertices: ";
	cin >> n;

	int **weight = new int*[n+1];
	for(int i = 0; i <= n; i++)
		weight[i] = new int[n+1];

	vector<pair<int, pair<int, int>>> edges;
	edges.push_back(make_pair(0, make_pair(0, 0))); // to start from 1

	cout << "Enter Weight matrix\n";
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(i == 0 || j == 0)
				weight[i][j] = 0;
			else {
				cin >> weight[i][j];
				if(weight[i][j] != 0)
					edges.push_back(make_pair(weight[i][j], make_pair(i, j)));
			}
		}
	}

	int mstcost = kruskal(edges, weight, n);
	cout << "Total cost of minimum spanning tree: " << mstcost << endl;

}
