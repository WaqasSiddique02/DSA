#include <iostream>
using namespace std;
int main() {
	const int size = 5;
	int arr[size] = {3,2,1,4,5};

	int var = arr[3];
	
	cout << "Elements of array are :" << endl;
	for (int i = 0; i < size;i++) {
		cout << arr[i];
	}

	return 0;
}