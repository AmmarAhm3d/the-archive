#include <iostream>
using namespace std;

// prototypes
void Input(int*& iarr, int& size); //why is size passed by reference for this?
								   //ANS: because size will be incremented if array gets full.
void reverse(int* iarr, int size);
void Output(int* iarr, int size);

int main()
{
	int size = 5;
	int* arr = new int[size];
	Input(arr, size);
	reverse(arr, size);
	Output(arr, size);

	return 0;
}

void Output(int* iarr, int size)
{
	for (int i = 0; i < size; i++)
		cout << *(iarr + i) << " ";
}


void reverse(int* iarr, int size) {
	int j = size-1;
    for(int i=0; i<j; i++, j--)
    {
		int temp = 0;
        temp = iarr[i];
        iarr[i] = iarr[j];
        iarr[j] = temp;
    }
}


void Input(int*& iarr, int& size) {
	int main_index = 0;
	do{
		int num = 0; cin >> num;
		if (num != -1) {
			*(iarr + main_index) = num;
			++main_index;
		}
		else
		{
			cout << "\"Size created " << size << "\"\n";
			size = main_index;
			break;
		}

		// final check if size reached
		if (main_index == size)
		{
			// get oldsize
			int old_size = size;

			// double size and make new array
			size *= 2;
			int* swap_arr = new int[size];

			// copy operation
			for (int index = 0; index < old_size; index++)
				*(swap_arr + index) = *(iarr + index);

			// swap pointers
			swap(iarr, swap_arr);

			// delete new pointer after swap
			swap_arr = nullptr;
			delete[] swap_arr;
		}
		
	} while (true);
}
