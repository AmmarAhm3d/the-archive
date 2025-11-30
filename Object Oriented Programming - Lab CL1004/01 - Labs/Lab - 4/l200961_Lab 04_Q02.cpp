#include <iostream>
#include <fstream>
using namespace std;

char filename[] = "matrix.txt";

class Matrix {
	int rows, cols;
	void setRows(int r) {
		rows = r;
	}
	void setCols(int c) {
		cols = c;
	}
	int getRows() {
		return rows;
	}
	int getCols() {
		return cols;
	}
	int** AllocateMemory(int r, int c) {
		int** matrix = new int* [r];
		for (int i = 0; i < r; i++)matrix[i] = new int[c]; return matrix;
	}

public:
	int** Input(char filename[], int** mat) {
		fstream fin(filename, ios::in);
		if (fin) {
			fin >> rows;
			fin >> cols;
			mat = AllocateMemory(rows, cols);
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					fin >> mat[i][j];
			
			return mat;
		}
		else
			cout << "invalid file ";
	}

	void Display(int** in) {
		for (int i = 0; i < getRows(); i++) {
			for (int j = 0; j < getCols(); j++)
				cout << in[i][j] << " ";
			cout << endl;
		}
	}

	void rotateOuterLayerBy1(int** mat) {
		int n = rows = cols;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = i; j < n - 1; j++)
			{
				int temp = mat[i][j];
				mat[i][j] = mat[j][n - 1 - i];
				mat[j][n - 1 - i] = mat[n - 1 - i][n - 1 - j];
				mat[n - 1 - i][n - 1 - j] = mat[n - 1 - j][i];
				mat[n - 1 - j][i] = temp;
			}
		}
	}

	void Deallocate(int** mat) {
		for (int i = 0; i < getRows(); i++)delete[]mat[i];
		delete[]mat;
		mat = nullptr;
	}
};

int main()
{
	Matrix m;
	int** mat = nullptr;
	mat = m.Input(filename, mat);
	m.Display(mat);
	m.rotateOuterLayerBy1(mat);
	cout << endl << endl;
	m.Display(mat);
	m.Deallocate(mat);


	return 0;
}