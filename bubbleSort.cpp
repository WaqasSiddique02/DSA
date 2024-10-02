#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int arr[size] = { 0, 2, 7, 1, 3, 9, 8, 0, 4, 22 };

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size -1- i; j++) {
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}