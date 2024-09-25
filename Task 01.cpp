#include <iostream>
using namespace std;

void reverseArray(int arr[],int size) {
	cout << "Revresed array: ";
	for (int i = size-1; i >= 0;i--) {
		cout << arr[i]<<" ";
	}
}

int maxElement(int arr[],int size) {
	int temp=0 ;
	for (int i = 0; i < size;i++) {
		if (temp<arr[i]) {
			temp = arr[i];
		}
	}
	return temp;
}

int minElement(int arr[], int size) {
	int temp = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < temp) {
			temp = arr[i]; 
		}
	}

	return temp;
}

int averageOfArray(int arr[],int size) {
	int sum=0;
	int avg = 0;
	for (int i = 0; i < size;i++) {
		sum += arr[i];
	}
	avg = sum / size;

	return avg;
}

int main() {
	const int size = 10;
	int arr[size] = { 7,5,6,12,35,42,18,23,50,4 };
	int max, min;
	reverseArray(arr, size);
	cout << endl;
	max = maxElement(arr, size);
	min = minElement(arr, size);
	cout<<"Maximum element of the array is "<<max <<endl;
	cout << "Minimum element of the array is " <<min << endl;
	cout<<"Average of the array is "<< averageOfArray(arr, size) << endl;

	return 0;
}
