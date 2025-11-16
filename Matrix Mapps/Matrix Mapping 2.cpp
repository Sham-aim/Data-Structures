#include <iostream>
using namespace std;
int* columnmapping(int a[][3], int column, int row) {
	int k = 0;
	int* new_array = new int[column * row];
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			new_array[k] = a[i][j];
			k++;
		}
	}
	return new_array;
}
int* rowmapping(int a[][3], int column, int row) {
	int k = 0;
	int* new_array = new int[column * row];
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			new_array[k] = a[j][i];
			k++;
		}
	}
	return new_array;
}
int* reverse_rowmapping(int a[], int column, int row) {
	int* new_array = new int[column * row];
	int k = 0;
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			new_array[i + j * row] = a[k];
			k++;
		}
	}
	return new_array;
}
int* reverse_columnmapping(int a[], int column, int row) {
	int* new_array = new int[column * row];
	int k = 0;
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			new_array[i * column + j] = a[k];
			k++;
		}
	}
	return new_array;
}
int* diagonal_store(int a[][3], int column, int row) {
	int* new_array = new int[column];
	int k = 0;
	for (int j = 0; j < column; j++) {
		new_array[k] = a[j][j];
		k++;

	}
	return new_array;
}
int* tridiagonal_store(int a[][3], int n) {
	int* new_array = new int[3 * n - 2];
	for (int j = 0; j < n; j++) {
		new_array[j] = a[j][j];
	}
	for (int i = 0; i < n - 1; i++) {
		new_array[i + n] = a[i + 1][i];
	}
	for (int i = 0; i < n - 1; i++) {
		new_array[i + n + (n - 1)] = a[i][i + 1];
	}
	return new_array;
}
int* lowertridiagonal_store(int a[][4], int n) {
	int* new_array = new int[2 * n + 2];
	for (int j = 0; j < n; j++) {
		new_array[j] = a[j][j];
	}
	for (int i = 0; i < n - 1; i++) {
		new_array[i + n] = a[i + 1][i];
	}
	for (int i = 0; i < n - 2; i++) {
		new_array[i + 2 * n - 1] = a[i + 2][i];
	}
	for (int i = 0; i < n - 3; i++) {
		new_array[i + 2 * n + 1] = a[i + 3][i];
	}
	return new_array;
}





int main()
{
	int array_2d[3][3] = { {1,2,3}, {4, 5, 6}, {7, 8, 9} };
	int* pointer = columnmapping(array_2d, 3, 3);
	cout << "Column Mapping a 2D Array" << endl;
	for (int i = 0; i < 3 * 3; i++) {
		cout << pointer[i] << " ";
	}
	cout << endl;
	int* pointer2 = rowmapping(array_2d, 3, 3);
	cout << "Row Mapping a 2D Array" << endl;
	for (int i = 0; i < 3 * 3; i++) {
		cout << pointer2[i] << " ";
	}
	cout << endl;
	int array_1d[9] = { 1,2,3,4,5,6,7,8,9 };
	int* pointer3 = reverse_rowmapping(array_1d, 3, 3);
	cout << "Reverse Row Mapping a 2D Array" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << pointer3[i * 3 + j] << " ";
		}
		cout << endl;
	}
	int* pointer4 = reverse_columnmapping(array_1d, 3, 3);
	cout << "Reverse Column Mapping a 2D Array" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << pointer4[i * 3 + j] << " ";
		}
		cout << endl;
	}
	int array_2d2[3][3] = { {1, 0, 0}, {0,1,0 }, {0,0,1} };
	int* pointer5 = diagonal_store(array_2d2, 3, 3);
	cout << "Storing Diagonal 2D Array in a 1D array" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				cout << pointer5[i] << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
	// Tinagular diagonal
	int array_2d3[3][3] = { {3,3,0},
						  {3,3,3},
						  {0,3,3} };
	int* pointer6 = tridiagonal_store(array_2d3, 3);
	cout << "Storing Triangular Diagonal 2D Array in a 1D array" << endl;
	//printing
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) {
				cout << pointer6[i] << " ";
			}
			else if (i - j == 1) {
				cout << pointer6[j + 3] << " ";
			}
			else if (j - i == 1) {
				cout << pointer6[3 + (3 - 1) + i] << " ";
			}
			else { cout << 0 << " "; }
		}
		cout << endl;

	}
	// lower triangular diagonal
	int array_2d4[4][4] = { {3,0,0,0},
						  {3,3,0,0},
						  {3,3,3,0},
						  {3,3,3,3} };
	int* pointer7 = lowertridiagonal_store(array_2d4, 4);
	cout << "Storing Lower Triangular Diagonal 2D Array in a 1D array" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				cout << pointer7[j] << " ";
			}
			else if (i - j == 1) {
				cout << pointer7[j + 3] << " ";
			}
			else if (i - j == 2) {
				cout << pointer7[j + 2 * 4 - 1] << " ";
			}
			else if (i - j == 3) {
				cout << pointer7[j + 2 * 4 + 1] << " ";
			}
			else { cout << 0 << " "; }
		}
		cout << endl;

	}









}


