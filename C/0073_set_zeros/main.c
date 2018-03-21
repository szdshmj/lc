#include "../inc.h"

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {

	int r = 0, c = 0;

	if(!matrix || matrixRowSize == 0 || matrixColSize == 0) return;

	for(int i = 0; i < matrixRowSize; i++) {
		for(int j = 0; j < matrixColSize; j++) {

			if(matrix[i][j] == 0) {
				if(i == 0) r = 1;
				if(j == 0) c = 1;
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for(int i = 1; i < matrixRowSize; i++) {
		for(int j = 1; j < matrixColSize; j++) {
			if(matrix[i][0] == 0 || matrix[0][j] ==0) {

				matrix[i][j] = 0;
			}
		}
	}

	if(r == 1) {
		for(int i = 0; i <matrixColSize; i++)
			matrix[0][i] = 0;
	}
	if(c == 1) {
		for(int i = 0; i <matrixRowSize; i++)
			matrix[i][0] = 0;
	}
}

