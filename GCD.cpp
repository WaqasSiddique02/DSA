#include <iostream>
using namespace std;
int main() {
	int no1, no2, gcd=0;
	int temp = 0;
	cout << "Enter two numbers" << endl;
	cin >> no1 >> no2;

	if (no1<no2) {
		temp = no1;
		no1 = no2;
		no2 = temp;
		cout << "Swaped numbers are " << no1<<" " << no2 << endl;
	}

	for (int i = 1; i < no2;i++) {
		if (no1%i==0 && no2%i==0) {
			gcd = i;
			cout << "GCD is " << gcd << endl;
			break;
		}
	}

	return 0;
}
