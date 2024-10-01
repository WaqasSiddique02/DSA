#include <iostream>
using namespace std;

class ArrayADT {
private:
    int* arr;
    int size=5;
    int capacity=10;

public:
    ArrayADT() {
        arr = new int[capacity];
        arr[0] = 18;
        arr[1] = 1;
        arr[2] = 9;
        arr[3] = 4;
        arr[4] = 5;
    }
    ~ArrayADT() {
        delete[] arr;
    }

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    void displayArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertElement(int pos, int value) {
        if (pos < 0 || pos > size) {
            cout << "Memory out of bounds" << endl;
            return;
        }

        if (size >= capacity) {
            cout << "Array full, resizng the array" << endl;
            resize();
        }

        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos] = value;
        size++;

        cout << "Array after insertion:" << endl;
        displayArray();
    }

    void updateElement(int pos, int value) {
        if (pos < 0 || pos >= size) {
            cout << "Memory out of bounds" << endl;
            return;
        }

        arr[pos] = value;

        cout << "Array after updation:" << endl;
        displayArray();
    }

    void deleteElement(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
            return;
        }

        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
        cout << "Array after deletion:" << endl;
        displayArray();
    }

    void linearSearch(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Value found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found in the array" << endl;
    }

    void bubbleSort() {
        bool swapped;

        for (int j = 0; j < size - 1; j++) {
            swapped = false;
            for (int i = 0; i < size - 1 - j; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }

            if (!swapped) {
                break; 
            }
        }

        cout << "Sorted array: ";
        displayArray();
    }
};

int main() {
    int val, pos;
    ArrayADT arr;
    int choice;

    do {
        cout << "1. Insert into array" << endl;
        cout << "2. Update element in the array" << endl;
        cout << "3. Delete from the array" << endl;
        cout << "4. Linear Search" << endl;
        cout << "5. Bubble Sort" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element you want to add:" << endl;
            cin >> val;
            cout << "Enter the position you want to add value at:" << endl;
            cin >> pos;
            arr.insertElement(pos, val);
            break;

        case 2:
            cout << "Enter the position you want to update:" << endl;
            cin >> pos;
            cout << "Enter the new value:" << endl;
            cin >> val;
            arr.updateElement(pos, val);
            break;

        case 3:
            cout << "Enter the position you want to delete:" << endl;
            cin >> pos;
            arr.deleteElement(pos);
            break;

        case 4:
            cout << "Enter the value you want to find:" << endl;
            cin >> val;
            arr.linearSearch(val);
            break;

        case 5:
            cout << "Bubble sort of the array:" << endl;
            arr.bubbleSort();
            break;

        case 0:
            return 0;

        default:
            cout << "Invalid option... try again" << endl;
        }
    } while (true);

    return 0;
}