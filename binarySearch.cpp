#include <iostream>
using namespace std;

int main() {
    const int size = 20;
    int arr[size] = { 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    const int target = 5;

    int left = 0, right = size - 1, mid = 0;

    for (int i = 0; left <= right; i++) {
        mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return 0; 
        }
        else if (arr[mid] > target) {  
            left = mid + 1;  
            cout << "Left=" << left<<endl;
        }
        else {
            right = mid - 1; 
            cout << "right=" << right<<endl;
        }

        cout << "Not found, continuing search..." << endl;
    }

    cout << "Element not found in the array." << endl;
    return 0;
}