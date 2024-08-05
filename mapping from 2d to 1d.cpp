#include <iostream>

using namespace std;

class Matrix {
private:
	int* data;
	int rows;
	int columns;

public:
	Matrix(int row, int column):rows(row),columns(column) {
		if (rows <= 0 ||  columns <= 0) {
			cerr << "ERROR.." << endl;
		}else{
			data = new int[rows * columns];
		}
	}

	~Matrix(){
		delete[] data;
	}

	int get(int i, int j) {
		if (i < 0 || i >= rows || j < 0 || j >= columns) {
			cerr << "OUT OF RANGE ENTER CORRECT ENTITIES ... " << endl;
		}
		else {
			return data[i * columns + j];

		}
	}

	void set(int i, int j,int v) {
		if (i < 0 || i >= rows || j < 0 || j >= columns) {
			cerr << "OUT OF RANGE ENTER CORRECT ENTITIES ... " << endl;
		}
		else {
			data[i * columns + j] = v;
		}
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << data[i * columns + j] << "  ";
			}
			cout << endl;
		}
	}

	void transpose() {
		int* tempData = new int[columns * rows]; 
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				tempData[j * rows + i] = data[i * columns + j];
			}
		}
		delete[] data;
		data = tempData;
		swap(rows, columns);
	}

	void printSubMatrix(int r1, int r2, int c1, int c2) {
		if (r1 < 0 || r1 >= rows || r2 < 0 || r2 >= rows || c1 < 0 || c1 >= columns || c2 < 0 || c2 >= columns) {
			cerr << "OUT OF RANGE ENTER CORRECT ENTITIES ... " << endl;
		}
		else {

			for (int i = r1; i <= r2; i++) {
				for (int j = c1; j <= c2; j++) {
					cout << data[i * columns + j] << " ";
				}
				cout << endl;
			}
		}
	}

	void makeEmpty(int n) {
		if (n<0 || n>rows || n > columns) {
			cerr << "OUT OF RANGE ENTER CORRECT VALUE OF N ... " << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					data[i * columns + j] = 0;
				}
			}
		}
	}

	void add(Matrix first, Matrix second) {
		if (first.rows != rows || first.columns != columns || second.rows != rows || second.columns != columns) {
			cerr << "ENTER SAME AND CORRECT ORDER VALUE ... " << endl;
		}
		else {
			delete[] data; 
			data = new int[rows * columns];

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					data[i * columns + j] = first.data[i * columns + j] + second.data[i * columns + j];
				}
			}
		}
	}
};

int main() {
	Matrix m1(2, 3);
	Matrix m2(2, 3);
	Matrix result(2, 3);

	m1.set(0, 0, 1);
	m1.set(0,1,2);
	m1.set(0, 2,3);
	m1.set(1,0,4);
	m1.set(1,1,5);
	m1.set(1,2,6);

	m2.set(0, 0, 1);
	m2.set(0, 1, 2);
	m2.set(0, 2, 3);
	m2.set(1, 0, 4);
	m2.set(1, 1, 57);
	m2.set(1, 2, 6);

	cout << "MATRIX 1 :" << endl;
	m1.print();


	cout << "MATRIX 2 :" << endl;
	m2.print();


	cout << "SUBMATRIX: (0-1,0-1)::" << endl;
	m2.printSubMatrix(0, 1, 0, 1);


	cout << "EMPTYING THE MATRIX: " << endl;
	m1.makeEmpty(2);
	m1.print();

	cout << "ADDITION OF MATRICES:" << endl;
	result.add(m1, m2);
	result.print();

	

}
