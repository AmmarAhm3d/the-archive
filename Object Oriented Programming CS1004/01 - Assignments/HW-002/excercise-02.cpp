// 20L-0961      Ammar Ahmed     HW-002, Excercise 02 //
#include <iostream>
using namespace std;

int* init(int getSize) {
	int* p = new int[getSize];
	return p;
}


int max_and_minAverage(int arr[] , int getSize) {

	int max, min;

	max = arr[0];
	min = arr[0];
	for (int i = 0; i < getSize; i++)
	{
		if (max < arr[i])
			max = arr[i];
		else if (min > arr[i])
			min = arr[i];
	}

	cout << "Largest element : " << max << endl;
	cout << "Smallest element : " << min << endl;

	int avg = (max + min) / 2;
	return avg;

}

void input(int* arr, int getSize) {
	for (int i = 0; i < getSize; i++)
		cin >> arr[i];
}



int main()
{
	cout << "Enter size of array : ";
	int size; cin >> size;
	int* arr = init(size);

	cout << "Enter elements : "; 
	input(arr, size);

	int avg = max_and_minAverage(arr, size);

	cout << "Average of max and min is : " << avg;


	return 0;
}