#include "../inc.h"

void dump(int** matrix, int m, int n) {

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {

	int n = matrixRowSize;
	for(int i = 0; i < n; i++) {
		
		for(int j = i; j < n - 1 - i; j++) {
			
			int tmp = matrix[i][j];	
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1- j];
			matrix[n - 1 - i][n - 1 -j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = tmp;
		}
	}
}

int main()
{
	int **aa, **bb;
	int a[3][3] = { //[0,0]->[0,n-1],[0,1]->[1,n-1],[0,2]->[2,n-1],,,,,[0, n-1]->[n-1,n-1]
		{1,2,3},	//[0,n-1]->[n-1,n-1],[1,n-1]->[n-1, n-2],,,,,[n-1][n-1]->[n-1,0]
		{4,5,6},	//[n-1,n-1]->[n-1, 0],[n-1, n-2]->[n-2,0],,,,[n-1,0]->[0,0]
		{7,8,9}		//[n-1,0]->[0,0],[n-2,0]->[0,1],,,,,,[0,0]->[0,n-1]
	};

	int b[4][4] = {
		{ 5, 1, 9,11},
		{ 2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};

	aa = malloc(sizeof(int *) * 3);
	for(int i = 0; i < 3; i++) {
		aa[i] = malloc(sizeof(int) * 3);
		for(int j = 0; j < 3; j++) {
			aa[i][j] = a[i][j];	
		}
	}

	bb = malloc(sizeof(int *) * 4);
	for(int i = 0; i < 4; i++) {
		bb[i] = malloc(sizeof(int) * 4);
		for(int j = 0; j < 4; j++) {
			bb[i][j] = b[i][j];	
		}
	}
	rotate(aa, 3, NULL);
	dump(aa, 3, 3);
	rotate(bb, 4, NULL);
	dump(bb, 4, 4);

	return 0;
}
