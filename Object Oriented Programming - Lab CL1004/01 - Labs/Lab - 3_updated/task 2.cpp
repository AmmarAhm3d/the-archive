#include <iostream>
#include <fstream>
using namespace std;

void Deallocation(int**& mat, int rows) {
	for (int i = 0; i < rows; i++)delete[] mat[i];
	mat = nullptr;
}

void Deallocation(int*& mat) {
	delete[]mat;
	mat = nullptr;
}

void loadMarix(char* filename, int** matrix, int& rows, int& col) {
	fstream fin(filename, ios::in);

	if (fin.is_open()) {
		fin >> rows; fin >> col;
		int** sparseMat = new int* [rows];
		for (int i = 0; i < rows; i++)sparseMat[i] = new int[col];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < col; j++)
				fin >> sparseMat[i][j];
		
		int* sizeArray = new int[rows];
		int* countArr = new int[rows];
		for (int i = 0; i < rows; i++) {
			sizeArray[i] = 1;
			countArr[i] = 0;
			for (int j = 0; j < col; j++)
				if (sparseMat[i][j] != 0) {
					// column index + value
					sizeArray[i] += 2, countArr[i]++;
				}
		}
		

		matrix = new  int* [rows];
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < sizeArray[i]; j++)
				matrix[i] = new int[sizeArray[i]];

		cout << "Elements " << "Column index " << "value ... " << endl;
		for (int i = 0; i < rows; i++) {
			matrix[i][0] = countArr[i];
			cout << matrix[i][0] << " ";
			for (int j = 0, k = 0; k < sizeArray[i] && j < col; j++) {
				if (sparseMat[i][j] != 0) {
					matrix[i][k] = 0;
					matrix[i][++k] = j;
					cout << matrix[i][k] << " ";
					matrix[i][++k] = sparseMat[i][j];
					cout << matrix[i][k] << " ";
				}
			}
			cout << endl;
		}
		Deallocation(sparseMat, rows);
		Deallocation(matrix, rows);
		Deallocation(sizeArray);
		Deallocation(countArr);

	}
	else
		cout << "File not read ";
}

int main()
{
	int** matrix = nullptr;
	int rows = 0, cols = 0;
	char filename[] = "sparse.txt";
	
	loadMarix(filename, matrix, rows, cols);

	return 0;
}
// commented code is old
/*#include <iostream>
#include <fstream>
using namespace std;

void Deallocation(int**& matrix, int rows) {
	for (int i = 0; i < rows; i++)delete[] matrix[i];
	matrix = nullptr;
}

int* loadMarix(char* filename, int** matrix, int& rows, int& col) {
	fstream fin(filename, ios::in);
	fin >> rows; fin >> col;
	int** sparseMat = new int* [rows];
	for (int i = 0; i < rows; i++)sparseMat[i] = new int[col];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < col; j++)
			fin >> sparseMat[i][j];

	int* sizeArray = new int[rows];
	for (int i = 0; i < rows; i++) {
		sizeArray[i] = 1;
		for (int j = 0; j < col; j++)
			if (sparseMat[i][j] != 0) {
				// column index + element
				sizeArray[i] += 2;
			}
	}

	matrix = new  int* [rows];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < sizeArray[i]; j++)
			matrix[i] = new int[sizeArray[i]];

	for (int i = 0; i < rows; i++) {
		int count = 0;
		for (int j = 0; j < col; j++) {
			if (sparseMat[i][j] != 0)
				matrix[i][0] = ++count;
			for (int k = 0; k < sizeArray[i]; k+=2) {
				matrix[i][k] = j;
				matrix[i][++k] = matrix[i][j];
			}
		}

	}
	Deallocation(sparseMat, rows);

	return sizeArray;

}

void print(int** matrix, int rows, int* colArray) //print the as Figure1. 
{
	cout << "Number of elements\t" << "Column index\t" << "value\t" << "Column index\t" << "value ... " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colArray[i]; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int** matrix = nullptr;
	int rows = 0, cols = 0;
	char filename[] = "sparse.txt";
	int* colArray = loadMarix(filename, matrix, rows, cols);

	print(matrix, rows, colArray);
	Deallocation(matrix, rows);

	return 0;
}*/