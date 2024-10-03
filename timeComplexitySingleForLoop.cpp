#include <iostream>
using namespace std;
int main() {
	int a = 0,b=0;
	int n = 4, m = 4;
	for (int i = 0; i < n;i++) {
		a = a + 10;
	}

	for (int i = 0; i < m;i++) {
		b = b + 40;
	}

	cout << a << " " << b << endl;
	return 0;
}
