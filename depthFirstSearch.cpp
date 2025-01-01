#include <iostream>
using namespace std;

class Graph {
    int V;
    int *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new int[V * V](); 
}

void Graph::addEdge(int v, int w) {
    adj[v * V + w] = 1;
    adj[w * V + v] = 1;
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < V; i++) {
        if (adj[v * V + i] == 1 && !visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
    delete[] visited;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS(2);

    return 0;
}
