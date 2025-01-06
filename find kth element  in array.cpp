#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapify(int i) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
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

    void pop() {
        if (heap.size() > 1) {
            heap[0] = heap.back();
            heap.pop_back();
            heapify(0);
        } else {
            heap.pop_back();
        }
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    size_t size() {
        return heap.size();
    }
};

int findKthLargest(vector<int>& nums, int k) {
    MinHeap minHeap;
    
    for (int i = 0; i < nums.size(); ++i) {
        minHeap.insert(nums[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}

int main() {
    vector<int> nums = {10, 5, 20, 15, 30, 25};
    int k = 3;
    cout << "The " << k << "th largest element is: " << findKthLargest(nums, k) << endl;
    return 0;
}
