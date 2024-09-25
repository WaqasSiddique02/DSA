#include <iostream>
using namespace std;

int main() {
	const int row = 4;
	const int coloumn = 2;

	int arr[row][coloumn] = { {10,11},
		{12,13},
		{14,15},
		{16,17}
	};

	cout << "Elemnets of 2D array are: " << endl;

	for (int i = 0; i < row;i++) {
		for (int j = 0; j < coloumn;j++) {
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}