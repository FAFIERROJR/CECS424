/*
Write your answer in C++ to the questions.
Upload your work via BeachBoard
*/

#include <iostream>
using namespace std;

int main() {
	int row = 3, col = 4;
	int** mat;
	mat = new int*[row];
	for (int r = 0; r < row; r++) {
		//1. replace the following line (mat[r]) with a pointer version (2 pts)
		//mat[r] = new int[col];
		*(mat + r) = new int[col];
	}
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			//2. replace the following line (mat[r][c]) with a pointer version (3 pts)
			//mat[r][c] = r * row + c;
			*(*(mat + r) + c) = r * row + c;
		}
	}

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			//3. replace the following line (mat[r][c] and &mat[r][c]) with a pointer version (5 pts)
			//cout << mat[r][c] << " (" << &mat[r][c] << ")\t";
			cout << (*(*(mat + r) + c)) << " (" << &(*(*(mat + r) + c)) << ")\t";
		}
		cout << endl;
	}
}