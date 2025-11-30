#include <iostream>
using namespace std;

int main()
{
	int x, y;
	x = 0, y = 0;
	int* p, * q;
	p = &x, q = &y;

	cout << x << " " << p << " " << *p << " " << " " << &p << " " << &x << endl;
	cout << y << " " << q << " " << *q << " " << &q << " " << &y;

	return 0;
}