#include <iostream>
using namespace std;

int main()
{
	int arr[5] = {20,30,40,60,70};
	int* ptr = arr;

	// OUtput

	for (int i = 0; i < 5; i++) {
		cout << ptr[i] << " ";
	}

	return 0;
}