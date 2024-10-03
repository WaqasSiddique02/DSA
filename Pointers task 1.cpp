#include <iostream>
using namespace std;

void pointer() {
	int var = 29;
	int* ptr;
	ptr = &var;

	cout << "value at ptr is " << ptr<<endl;
	cout << "value at var is " << var << endl;
	cout << "value at *ptr is " << *ptr << endl;
}

int main() {
	pointer();
	return 0;
}
