// 20L-0961      Ammar Ahmed     ASM-001, Question 02 //
#include <iostream>
using namespace std;

int** init(int r, int c) {
	int** arr = new  int* [r];
	for (int i = 0; i < r; i++) arr[i] = new int[c]; return arr;
}

void out(int** arr, int r, int c) {
	for (int i = 0; i < r; i++) {
		cout << "| ";
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << " ";
		cout << "|" << endl;
	}
	cout << endl;
}

void out(int arr[][6], int r, int c) {
	for (int i = 0; i < r; i++) {
		cout << "| ";
		for (int j = 0; j < c; j++)
			cout << arr[i][j] << " ";
		cout << "|" << endl;
	}
	cout << endl;
}

int** compress_ones(int arr[][6], int r, int c) {
	// we only make two columns in this
	int** ones = init(r, 2);

	for (int i = 0; i < r; i++) {
		ones[i][0] = 0;
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 1) {
				ones[i][0] += arr[i][j];
				ones[i][1] = 1;
			}
		}
	}

	return ones;
}

int** loc_ones(int arr[][6], int r, int c) {
	int** loc = init(r, c);
	int count = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			++count;
			loc[i][j] = 0;
			if (arr[i][j] == 1)
				loc[i][j] = count;
		}
	}

	return loc;
}

int** make(int** loc, int** ones, int rl, int cl) {
	// first make 2d array, from the loc array parameters
	int** arr = init(rl, cl);

	// iterating through location array to grab indexes
	int count = 0;
	for (int i = 0; i < rl; i++) {
		for (int j = 0; j < cl; j++) {
			++count;
			arr[i][j] = 0;
			if (loc[i][j] == count) {
				arr[i][j] = ones[i][1];
			}

		}
	}

	return arr;
}

int main()
{
	// taking 5x6 matrix from assignment
	int bin_arr[][6] = {
	 {1, 1, 1, 0, 0, 0}
	,{0, 0, 0, 1, 1, 0}
	,{1, 0, 0, 0, 0, 0}
	,{1, 1, 1, 0, 0, 1}
	,{1, 0, 0, 0, 1, 0}
	};

	out(bin_arr, 5, 6);

	// making first 2D array containing count of 1s
	int** ones = compress_ones(bin_arr, 5, 6);
	cout << "Output Array-01: \n";
	out(ones, 5, 2);


	int** loc = loc_ones(bin_arr, 5, 6);
	cout << "Output Array-02: \n";
	out(loc, 5, 6);


	// passing both intermediates to get combined matrix
	int** transform = make(loc, ones, 5, 6);
	cout << "Transformed 2D array: \n";
	out(transform, 5, 6);

	return 0;
}