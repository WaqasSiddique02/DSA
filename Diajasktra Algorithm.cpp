#include <iostream>
using namespace std;

const int infinity = 999999999;
const int maxNode = 100;

int findMinDistance(int distance[],bool visited[],int n) {
	int minDist = infinity;
	int minIndex = -1;

	for (int i = 0; i < n;i++) {
		if (!visited[i]&&distance[i]<minDist) {
			minDist = distance[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void dijasktra(int graph[maxNode][maxNode],int n,int start) {
	int distance[maxNode];
	bool visited[maxNode] = { false };

	for (int i = 0; i < n;i++) {
		distance[i] = infinity;
	}
	distance[start] = 0;

	for (int i = 0; i < n - 1;i++) {
		int u = findMinDistance(distance, visited, n);
		if (u==-1) {break;}
		visited[u] = true;

		for (int v = 0; v < n; v++) {
			if (!visited[v] && graph[u][v]&&distance[u]!=infinity&&distance[u]+graph[u][v]<distance[v]) {
				distance[v] = distance[u] + graph[u][v];
			}
		}
	}

	cout << "distance from the start "<<endl;
	for (int i = 0; i < n;i++) {
		cout << i << "\t";
		if (distance[i]==infinity) {
			cout << "-1";
		}
		else {
			cout << distance[i]<<"\n";
		}
	}
	
}

int main() {
	int n, start;
	cout << "Enter the number of nodes " << endl;
	cin >> n;
	int graph[maxNode][maxNode] = { 0 };
	cout << "Enter the adjacency matrix (use 0 for no edge): \t";
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> graph[i][j];
		}
	}

	cout << "Enter the starting node" << endl;
	cin >> start;

	dijasktra(graph, n, start);

	return 0;
}
