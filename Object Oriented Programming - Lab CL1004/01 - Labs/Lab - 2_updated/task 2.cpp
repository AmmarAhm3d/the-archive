#include <iostream>
using namespace std;

int* genFib(int n) {
	int* arr = new int[n];	
	
	if(n == 1)
		arr[0] = 1;
	if(n == 2)
		arr[1] = 1;
	else if(n > 2)
		for (int i = 2; i < n; i++)
			arr[i] = arr[i - 1] + arr[i - 2];
	/*
	cout << "\nFibonacci Numbers: ";
	for (int i = 0; i < n; i++)	cout << arr[i] << ", ";
	*/

	// for part b
	return arr;
}

void Output(int* myptr, int size) {
	myptr = genFib(size);
	cout << "\nFibonacci Numbers: ";
	for (int i = 0; i < size; i++)	cout << myptr[i] << ", ";
}

int main()
{
	int size; cout << "Please enter size: "; cin >> size;
	
	if(size > 0){
	// Part a
	genFib(size);

	// Part b
	int* arr = nullptr;
	Output(arr, size);
	}
	else
		cout << "Invalid size ";

	return 0;
}