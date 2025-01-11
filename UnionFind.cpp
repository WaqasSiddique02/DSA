#include <iostream>
using namespace std;

const int maxSize = 100;

class disjointSet {
private:
    int parent[maxSize];
    int rank[maxSize];

public:
    disjointSet() {
        for (int i = 0; i <maxSize; i++) {
            parent[i] = -1;
            rank[i] = 0;
        }
    }

    void setParent(int index,int value) {
        if (index>=0&&index<=maxSize) {
            parent[index] = value;
        }
        else {
            cout << "Index out of bound " << endl;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    void displayParent(int n) {
        cout << "Parent Array: ";
        for (int i = 0; i < n; i++) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter total elements: ";
    cin >> n;

    disjointSet ds;

    cout << "Set parent array elements manually:" << endl;
    for (int i = 0; i < n; i++) {
        int parentValue;
        cout << "Enter parent for element " << i << ": ";
        cin >> parentValue;
        ds.setParent(i, parentValue);
    }

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    for (int i = 0; i < q; i++) {
        int op;
        cout << "Choose operation (1: Union, 2: Find): ";
        cin >> op;

        if (op == 1) {
            int x, y;
            cout << "Enter the two elements to union: ";
            cin >> x >> y;
            ds.unionSets(x, y);
        }
        else if (op == 2) {
            int x;
            cout << "Enter the element to find its root: ";
            cin >> x;
            cout << "Root of " << x << " is " << ds.find(x) << endl;
        }
        else {
            cout << "Invalid operation!" << endl;
        }

        ds.displayParent(n);
    }

    return 0;
}