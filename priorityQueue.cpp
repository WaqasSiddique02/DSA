#include <iostream>
using namespace std;

const int maxSize = 100;
class priorityQueue {
private:
	int heap[maxSize];
	int size;

	void heapifyUp(int index) {
		while (index > 0) {
			int parent = (index - 1) / 2;
			if (heap[index]>heap[parent]) {
				swap(heap[index], heap[parent]);
				index = parent;
			}
			else {
				break;
			}
		}
	}

	void heapifyDown(int index) {
		int largest = index;
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;

		if (leftChild<size&&heap[leftChild]>heap[largest]) {
			largest = leftChild;
		}
		if (rightChild<size&&heap[rightChild]>heap[largest]) {
			largest = rightChild;
		}
		if (largest!=index) {
			swap(heap[index], heap[largest]);
			heapifyDown(largest);
		}
	}

public:
	priorityQueue() {
		size = 0;
	}

	void push(int value) {
		if (size==maxSize) {
			cout << "Priority queue is full" << endl;
		}

		heap[size] = value;
		heapifyUp(size);
		size++;
	}

	void pop() {
		if (size==0) {
			cout << "priority queue is empty" << endl;
			return;
		}
		heap[0] = heap[size - 1];
		size--;
		heapifyDown(0);
	}

	int top() {
		if (size==0) {
			cout << "priority queue is empty!" << endl;
			return -1;
		}
		return heap[0];
	}

	bool empty() {
		return size == 0;
	}

	void display() {
		for (int i = 0; i < size;i++) {
			cout << heap[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	priorityQueue pq;

	pq.push(10);
	pq.push(20);
	pq.push(5);
	pq.push(30);

	cout << "Priority Queue: ";
	pq.display(); // Should display the heap structure

	cout << "Top element: " << pq.top() << endl; // Should return 30

	pq.pop(); // Remove 30
	cout << "Priority Queue after pop: ";
	pq.display();
}
