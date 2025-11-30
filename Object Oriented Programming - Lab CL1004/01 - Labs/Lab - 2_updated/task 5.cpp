#include <iostream>
using namespace std;

void Input(int* arr, int size) {
	for (int i = 0; i < size; i++)cin >> arr[i];
}

void Output(int* arr, int size) {
	for (int i = 0; i < size; i++)cout << arr[i] << " ";
}

int* Compression(int* arr, int& size) {
	int temp[999] = { 0 };

	int j = 0;
	for (int i = 0; i < size - 1; i++)
		if (arr[i] != arr[i + 1])
			temp[j++] = arr[i];
	temp[j++] = arr[size - 1];

	for (int i = 0; i < j; i++)
		arr[i] = temp[i];

	size = j;
	int* new_array = new int[j];
	new_array = { 0 };
	swap(arr, new_array);

	arr = nullptr;
	delete[] arr, temp;

	return new_array;
}


int main()
{
	int size;
	cout << "Enter the size of array" << endl;
	cin >> size;
	int* c1 = new int[size];
	cout << "Input elements in array: ";
	Input(c1, size);
	//Compressing the array
	int* p2 = Compression(c1, size);
	cout << "Array after compression will be: ";
	Output(p2, size);
	return 0;
}