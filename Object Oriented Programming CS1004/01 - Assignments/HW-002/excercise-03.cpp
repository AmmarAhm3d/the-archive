// 20L-0961      Ammar Ahmed     HW-002, Excercise 03 //
#include <iostream>
using namespace std;


void display(int arr[], int getSize) {
	for (int i = 0; i < getSize; i++)
		cout << arr[i] << " ";
}

int* initDouble(int arr[], int getSize) {
	int size = getSize * 2;
	int* arr_new = new int[size];

	for (int i = 0; i < size; i++) {
		while (i < getSize) {
			// copy contents
			arr_new[i] = arr[i];
			i++;
		}
		// append 0s to new sector
		arr_new[i] = 0;

	}

	return arr_new;
}


int main()
{
	const int size = 10;
	int test[size] = { 1,2,3,4,5,6,7,8,9,10 };
	display(test, size);
	int* arr = initDouble(test, size);

	cout << endl;
	display(arr, size*2);

	return 0;
}