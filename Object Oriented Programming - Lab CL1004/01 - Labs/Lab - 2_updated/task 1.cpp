#include <iostream>
using namespace std;

float* init(int getSize) {
	float* arr = new float[getSize];	return arr;
}

void input(float* in, int getSize) {
	cout << "Please enter elements: ";

	for (int i = 0; i < getSize; i++)cin >> in[i];
}

void secondLargest(float* arr, int getSize) {
	float large = arr[0];
	for (int i = 0; i < getSize; i++)
	{
		if (large < arr[i])
			large = arr[i];
	}
	float slarge = arr[0]; int index = 0;
	for (int i = 0; i < getSize; i++)
	{
		if (slarge < arr[i])
		{
			if (arr[i] != large) {
				slarge = arr[i];
				index = i;
			}
		}
	}
	cout << "\nSecond Largest Element is: " << slarge << endl;
	cout << "Index of second largest element is: " << index;

}

int main()
{
	float size; cout << "Please enter size: "; cin >> size;

	float* arr=init(size);

	input(arr, size);

	secondLargest(arr, size);

	return 0;
}