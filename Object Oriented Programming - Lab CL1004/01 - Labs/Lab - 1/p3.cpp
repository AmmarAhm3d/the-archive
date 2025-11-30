#include <iostream>
using namespace std;

int SUM1(int& a, int& b) {
	int z = 0;
	z = a + b;
	return(z);
}

int SUM2(int a, int b) {
	int z = 0;
	z = a + b;
	return(z);
}

int main()
{
	int n1, n2, res = 0;

	cout << "Enter two numbers ";
	cin >> n1 >> n2;

	cout << "Sum by refrence "<<SUM1(n1, n2);
	cout << "Sum by value "<< SUM2(n1, n2);


	return 0;
}