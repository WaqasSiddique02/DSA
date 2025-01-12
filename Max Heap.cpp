#include <iostream>
using namespace std;

class maxHeap {
private:
	int* arr;
	int maxSize;
	int heapSize;

	void heapifyDown(int index) {
		int largest = index;
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;

		if (leftChild<heapSize && arr[leftChild]>arr[largest]) {
			largest = leftChild;
		}
		
		if (rightChild<heapSize && arr[rightChild]>arr[largest]) {
			largest = rightChild;
		}
		
		if (largest != index) {
			swap(arr[largest],arr[index]);
			heapifyDown(largest);
		}
	}

	void heapifyUp(int index) {
		int parent = (index - 1) / 2;
		if (index>0&&arr[index]>arr[parent]) {
			swap(arr[index],arr[parent]);
			heapifyUp(parent);
		}
	}

public:
	maxHeap(int size) {
		maxSize = size;
		heapSize = 0;
		arr = new int[maxSize];
	}

	void insert(int value) {
		if (heapSize>=maxSize) {
			cout << "heap overflow" << endl;
			return;
		}

		arr[heapSize] = value;
		heapSize++;
		heapifyUp(heapSize-1);
	}

	int extractMax() {
		if (heapSize<=0) {
			cout << "Heap underflow" << endl;
			return -1;
		}

		int maxElement = arr[0];
		arr[0] = arr[heapSize - 1];
		heapSize--;

		heapifyDown(0);
		return maxElement;
	}

	void display() {
		for (int i = 0; i < heapSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	maxHeap mh(10);
	mh.insert(10);
	mh.insert(20);
	mh.insert(5);
	mh.insert(8);
	mh.insert(15);

	cout << "Heap Elements= " << endl;
	mh.display();

	cout << "Extract max" << mh.extractMax() << endl;
	cout << "Elements after extraction" << endl;
	mh.display();

	return 0;
}
