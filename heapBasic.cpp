#include <iostream>
#include <vector>
using namespace std;

class minHeap {
private:
    vector<int> heap;

    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        int i = heap.size() - 1;
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void deleteValue(int value) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) return;
        heap[index] = heap.back();
        heap.pop_back();
        heapify(index);
    }

    int getMin() {
        if (!heap.empty()) return heap[0];
        return -1;
    }
};

int main() {
    cout << "Enter the number of queries: ";
    int Q;
    cin >> Q;

    minHeap heap;

    cout << "For each query, input one of the following:"<<endl;
    cout << "1 - insert x into the heap:"<<endl;
    cout << "2 - delete x from the heap:"<<endl;
    cout << "3 - print the minimum element in the hea:"<<endl;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cout << "Enter the value to insert: ";
            cin >> x;
            heap.insert(x);
        } else if (type == 2) {
            int x;
            cout << "Enter the value to delete: ";
            cin >> x;
            heap.deleteValue(x);
        } else if (type == 3) {
            cout << "Minimum element: " << heap.getMin() << endl;
        } else {
            cout << "Invalid query type. Please enter 1, 2, or 3:"<<endl;
        }
    }

    return 0;
}
