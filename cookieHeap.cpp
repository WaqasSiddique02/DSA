#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
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
        cout << "Inserted value: " << value << endl;
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return minVal;
    }

    int size() {
        return heap.size();
    }
};

int cookies(int k, vector<int>& A) {
    MinHeap heap;
    for (int i = 0; i < A.size(); i++) {
        heap.insert(A[i]);
    }

    int operations = 0;

    while (heap.size() > 1) {
        int first = heap.extractMin();
        cout << "Extracted first: " << first << endl;
        if (first >= k) break;

        int second = heap.extractMin();
        cout << "Extracted second: " << second << endl;
        if (second >= k) {
            heap.insert(first);
            break;
        }

        int combined = first + 2 * second;
        cout << "Combined new sweetness: " << combined << endl;  
        heap.insert(combined);
        operations++;
    }

    int finalMin = heap.extractMin();
    if (finalMin < k) {
        return -1;
    }

    return operations;
}

int main() {
    int n, k;
    cout << "Enter the number of cookies and the sweetness threshold: ";
    cin >> n >> k;
    vector<int> A(n);
    cout << "Enter the sweetness values of the cookies: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = cookies(k, A);
    cout << "Result: " << result << endl;
    return 0;
}
