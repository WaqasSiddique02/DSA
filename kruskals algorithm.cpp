#include <iostream>
using namespace std;

struct Edge {
	int src, dest, weight;
};

class disjointSet {
public:
	int parent[100];
	int rank[100];

	disjointSet(int n) {
		for (int i = 0; i < n;i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}


	int find(int x) {
		if (parent[x]!=x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void merge(int x,int y) {
		int rootX = find(x);
		int rootY = find(y);

		if (rootX!=rootY) {
			if (rank[rootY]>rank[rootX]) {
				parent[rootX] = rootY;
			}
			else if (rank[rootX]>rank[rootY]) {
				parent[rootY] = rootX;
			}
			else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}
};

void bubbleSort(Edge edge[],int E) {
	for (int i = 0; i < E - 1;i++) {
		for (int j = 0; j < E - i-1;j++) {
			if (edge[j].weight>edge[j+1].weight) {
				Edge temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}
		}
	}
}

int main() {
	int V, E;
	cout << "Enter the number of vertices" << endl;
	cin >> V;

	cout << "Enter the number of edges" << endl;
	cin >> E;

	Edge edges[100];
	cout << "Enter edges (src ,des,weight)" << endl;
	for (int i = 0; i < E;i++) {
		cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
	}
	
	bubbleSort(edges, E);

	disjointSet ds(V);

	int mstWeight = 0;
	cout << "edges in the minimum spanning tree" << endl;

	for (int i = 0; i < E;i++) {
		int u = edges[i].src;
		int v = edges[i].dest;

		if (ds.find(u)!=ds.find(v)) {
			ds.merge(u, v);
			mstWeight += edges[i].weight;
			cout << u << "-" << v << " : " << edges[i].weight << "\n";
		}
	}

	cout << "Total weight of mst : " << mstWeight << endl;
	return 0;
}
