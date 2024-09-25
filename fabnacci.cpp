#include <iostream>
using namespace std;
int main() {
	int t1 = 0, t2 = 1, t3 = 0;
	int no;

	cout << "Enter the amount of numbers you want to find" << endl;
	cin >> no;

	cout << t1 << " " << t2 << " ";

	for (int i = t2; i < no;i++) {
		t3 = t1 + t2;
		cout << t3 << " ";
		t1 = t2;
		t2 = t3;
	}

	return 0;
}
