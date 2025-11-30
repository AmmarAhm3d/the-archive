// 20L-0961      Ammar Ahmed     ASM-001, Question 01 //
#include <iostream>
using namespace std;

int* init(int size) {
	int* arr = nullptr;
	arr = new int[size]; return arr;
}

int** init(int qRows, int qCols) {
	int** arr = new  int* [qRows];
	for (int i = 0; i < qRows; i++)
		arr[i] = new int[qCols];
	return arr;
}

void input(int** arr, int rows, int cols) {
	cout << "Enter values:\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)cin >> arr[i][j];
	}
	cout << "\n";
}

void out(int** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		cout << "| ";
		for (int j = 0; j < cols; j++)
			cout << *(*(arr + i) + j) << " ";
		cout << "|" << endl;
	}
}

bool findZero(int n) {
	return n != 0;
}

void sliceZeros(int** arr, int qRows, int qCols) {
	// make a column array containing size for said row
	int* col = init(qRows);

	// traverse array and find 0s and make respective col array
	for (int i = 0; i < qRows; i++)
	{
		int size = 0;
		for (int j = 0; j < qCols; j++)
			if (findZero(arr[i][j]))
				++size;
		col[i] = size;
		cout << "columns size made " << col[i] << endl;
	}

	// making new 2d array of custom-sized colums per row
	int** slice = new  int* [qRows];
	for (int i = 0; i < qRows; i++)
		for (int j = 0; j < col[i]; j++)
			slice[i] = new int[col[i]];

	cout << "\nFollowing array was made \n";
	// traverse again and push into 2d array
	for (int i = 0; i < qRows; i++)
	{
		cout << "| ";
		for (int j = 0, y = 0; j < qCols && y < col[i]; j++)
			if (findZero(arr[i][j]))
			{
				// get size of column
				// push or place into slice
				slice[i][y] = arr[i][j];
				cout << slice[i][y++] << " ";
			}
		cout << "|" << endl;
	}

	// I chose to console output here as we cannot return two arrays at same time
	// deletion of queried array
	for (int i = 0; i < qRows; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}

int main()
{
	/*TEST on a 5x6 matrix
	int arr[][6] = {
		{2, 3, 1, 0, 0, 0 }
	   ,{0, 0, 0, 1, 1, 0 }
	   ,{1, 0, 0, 0, 0, 0 }
	   ,{1, 1, 1, 2, 0, 2 }
	   ,{5, 0, 0, 0, 10,0 }
	};
	out(arr, 5, 6);
	cout << endl;
	sliceZeros(arr, 5, 6);
	TEST succeeded
	FIND final code below	*/

	int** iarr = nullptr, r, c;
	cout << "Enter Row size and Column size "; cin >> r >> c;
	iarr = init(r, c);
	input(iarr, r, c);
	sliceZeros(iarr, r, c);

	return 0;
}