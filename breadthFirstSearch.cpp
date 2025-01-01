#include <iostream>
#include <queue>

using namespace std;

class Graph {
    int V;
    int* adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new int[V * V]();
}

void Graph::addEdge(int v, int w) {
    adj[v * V + w] = 1;
    adj[w * V + v] = 1;
}

void Graph::BFS(int s) {
    bool* visited = new bool[V]();
    queue<int> q;
    visited[s] = true;
    q.push(s);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        for (int v = 0; v < V; v++) {
            if (adj[u * V + v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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
    cout << "Following is Breadth First Traversal: ";
    g.BFS(2);
    return 0;
}
