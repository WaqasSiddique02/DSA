#include <iostream>
using namespace std;

class staticArray {
private:
	const static int capacity = 10;
	int size = 5;
	int arr[capacity] = {1,2,3,4,5};
public:
	int val,pos;
	staticArray() {
		val = 0;
		pos = 0;
	}

	~staticArray(){}

	void displayArray() {
		cout << "Static Array : " << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i]<<" ";
		}
	}

	void insertElement() {
		cout << "inserting an element in the array " << endl;
		cout << "Enter the element you want to add" << endl;
		cin >> val;
		cout << "Enter the positiion you want to add val at" << endl;
		cin >> pos;

		if (pos<0||pos>size) {
			cout << "position out of bounds" << endl;
			return;
		}

		if (size>=capacity) {
			cout << "Maximum capacity reached cannot add more elements in the static array " << endl;
			return;
		}

		for (int i = size; i > pos;i--) {
			arr[i] = arr[i - 1];
		}

		arr[pos] = val;
		++size;
		displayArray();
	}

	void deleteElement() {
		cout << "Deleting an element in the static array" << endl;
		cout << "enter the postion of the value you want to delete" << endl;
		cin >> pos;
		if (pos<0||pos>size) {
			cout << "postion out of bounds " << endl;
			return ;
		}

		for (int i = pos; i < size;i++) {
			arr[i] = arr[i + 1];
		}
		--size;
		displayArray();
	}

};

class dynamicArray {
private:
	int capacity = 10;
	int size = 5;
	int *arr;
public:
	int val, pos;
	dynamicArray() {
		arr = new int[capacity];
		arr[0] = 6;
		arr[1] = 7;
		arr[2] = 8;
		arr[3] = 9;
		arr[4] = 10;
		val = 0;
		pos=0;
	}
	~dynamicArray() {
		delete[] arr;
	}

	void display() {
		cout << "Dynamic Array : " << endl;
			for (int i = 0; i < size; i++) {
				cout << arr[i] << " ";
			}
	}

	void insertElement() {
		cout << "Insertion of element in dynamic array " << endl;
		cout << "Enter the element you want to add" << endl;
		cin >> val;
		cout << "Enter the position you want the value at " << endl;
		cin >> pos;

		if (pos<0|| pos>size) {
			cout << "Position out of reaach " << endl;
			return;
		}

		if (size >= capacity) {
		int newCapacity = capacity*2;
		int *newArr = new int[newCapacity];
		for (int i = 0; i < size;i++) {
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		capacity = newCapacity;
		}

		for (int i = size; i > pos; i--) {
			arr[i] = arr[i - 1];
		}

		arr[pos] = val;
		++size;

		display();
	}

	void deleteElement() {
		cout << "Deleting an element in the dynamic array" << endl;
		cout << "enter the postion of the value you want to delete" << endl;
		cin >> pos;
		if (pos<0 || pos>size) {
			cout << "postion out of bounds " << endl;
			return;
		}

		for (int i = pos; i < size; i++) {
			arr[i] = arr[i + 1];
		}
		--size;
		display();
	}

};

int main() {
	staticArray staticArr;
	dynamicArray dynamicArr;
	int choice, arrayType, action;

	do {
		cout << endl<<"Choose Array Type:" << endl;
		cout << "1. Static Array" << endl;
		cout << "2. Dynamic Array" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> arrayType;

		if (arrayType < 1 || arrayType > 3) {
			cout << "Invalid option. Please choose a valid array type." << endl;
			continue;
		}

		if (arrayType == 3) {
			cout << "Exiting program..." << endl;
			break;
		}

		do {
			cout << "\nChoose Action:" << endl;
			cout << "1. Display Array" << endl;
			cout << "2. Insert Element" << endl;
			cout << "3. Delete Element" << endl;
			cout << "4. Go Back to Array Type Selection" << endl;
			cout << "Enter your action: ";
			cin >> action;

			if (action < 1 || action > 4) {
				cout << "Invalid action. Please choose a valid option" << endl;
				continue;
			}

			switch (action) {
			case 1:
				if (arrayType == 1) {
					staticArr.displayArray();
				}
				else {
					dynamicArr.display();
				}
				break;
			case 2:
				if (arrayType == 1) {
					staticArr.insertElement();
				}
				else {
					dynamicArr.insertElement();
				}
				break;
			case 3:
				if (arrayType == 1) {
					staticArr.deleteElement();
				}
				else {
					dynamicArr.deleteElement();
				}
				break;
			case 4:
				cout << "Returning to Array Type Selection..." << endl;
				break;
			default:
				cout << "Unknown option." << endl;
			}
		} while (action != 4);

	} while (arrayType != 3);

	return 0;
}