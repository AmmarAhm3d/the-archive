#include <iostream>
using namespace std;

int** AllocateMemory(int& rows, int& cols) {
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)arr[i] = new int[cols]; return arr;
}

void InputMatrix(int** matrix, const int rows, const int cols) {
	for (int i = 0; i < rows; i++) 
		for (int j = 0; j < cols; j++)
			cin >> matrix[i][j];
	
}

void DisplayMatrix(int** matrix, const int& rows, const int&
cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int* maxCol(int** mat, const int rows, const int cols) {
	int* maxColValues = new int[cols];
	
	for (int i = 0; i < cols; i++) {
		maxColValues[i] = mat[0][i];
		for (int j = 1; j < rows; j++) {
			if (mat[j][i] > maxColValues[i])
				maxColValues[i] = mat[j][i];
		}
	}

	return maxColValues;
}

void DeallocateMemory(int** matrix, const int& rows) {
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	matrix = nullptr;
}

void main()
{
	int rows, cols;
	cout << "Enter rows and cols for matrix ";
	cin >> rows >> cols;
	int** matrix = AllocateMemory(rows, cols);
	DisplayMatrix(matrix, rows, cols);
	InputMatrix(matrix, rows, cols);
	int* maxColValues = maxCol(matrix, rows, cols);
	for (int i = 0; i < cols; i++)
		cout << *(maxColValues + i) << ",";
	cout << endl;
	DeallocateMemory(matrix, rows);
	delete[]maxColValues;
	maxColValues = nullptr;
}