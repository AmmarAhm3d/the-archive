#include <iostream>
using namespace std;

int main()
{
	const int a = 5;
	const int b = 10;
	const int c = 12;

	const int* p1 = &a, * p2 = &b, * p3 = &c;

	cout << "Median ";
	if ((*p1 < *p2 && *p2 < *p3) || (*p3 < *p2 && *p2 < *p1))
		cout << *p2;
	else if ((*p2 < *p1 && *p1 < *p3) || (*p3 < *p1 && *p1 < *p2))
		cout << *p1;
	else
		cout << *p3;

	// PArt b
	// "Constant" type-qualifer does not allows us to change values 


	return 0;
}