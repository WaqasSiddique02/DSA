#include <iostream>
using namespace std;
int main() {
	int t1 = 0, t2 = 1, t3 = 0;
	int no;

	cout << "Enter the amount of numbers you want to find" << endl;
	cin >> no;

	for (int i = 0; t3 < no ; i++) {
		cout << t3 << " ";
		t3 = t1 + t2;
		t1 = t2;
		t2 = t3;
		
	}

	return 0;
}
