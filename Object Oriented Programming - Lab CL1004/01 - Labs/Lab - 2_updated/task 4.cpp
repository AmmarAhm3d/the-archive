#include <iostream>
using namespace std;

void input(int* in, int size) {
	cout << "Please enter elements: ";
	for (int i = 0; i < size; i++)	cin >> in[i];
}

void copyArray(int* arr, int*& arr1, int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] != -1)
			arr1[i] = arr[i];
	}
}

int reduceArray(int* arr, int*& arr1, int size) {
	int red; cout << "Please enter the reduced size of array: "; cin >> red;
	red = size - red;
	// emplacing a placeholder digit, which we can use in copyfunction
	for (int i = 0; i < red; i++)
		arr[i] = -1;
	copyArray(arr, arr1, size);
	


	cout << "Array after reduction is \n";
	for (int i = 0; i < size; i++)
		if(arr1[i]!=- 842150451L)
		cout << arr1[i] << " ";

	return 0;
}

int main()
{
	int size; cout << "Please enter size: "; cin >> size;
	int* arr = new int[size];
	int* arr1 = new int[size];
	input(arr, size);
	
	reduceArray(arr, arr1, size);

	arr = nullptr;
	delete[] arr;

	return 0;
}