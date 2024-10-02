#include <iostream>
using namespace std;
int c = 4;
int o = 0;
void recurse(int n)
{
	if (n <= 0)
		return;
	else {
		o = o + 1;
	}
	recurse(n / c);	
}
void main()
{
	recurse(500);
	cout << o;
}
