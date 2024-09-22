#include <iostream>
using namespace std;

int main() {
	int arr[] = { 3,2,1,4,5 };
	int target = 6;
	const int size = sizeof(arr)/sizeof(arr[0]);
	cout << "size of the array : " << size<<endl;
	bool found = false;

	for (int i = 0; i < size;i++) {
		if (arr[i] == target) {
			cout << "Element is present at position " << i+1 << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Element not found in the array" << endl;
	}

	return 0;
}