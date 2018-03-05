#include "../inc.h"

void dump(int* matrix, int matrixRowSize, int matrixColSizes) {

	for(int i = 0; i < matrixRowSize; i++) {
		for(int j = 0; j < matrixColSizes; j++)
			printf("%2d ", *(matrix + i * matrixColSizes + j));
		printf("\n");
	}
}

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {

}

int main()
{
	int a[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	int b[4][4] = {
		{ 5, 1, 9,11},
		{ 2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};

	//rotate((int **)a, 3, 3);
	dump((int *)a, 3, 3);
	//rotate((int **)b, 4, 4);
	dump((int *)b, 4, 4);
	return 0;
}
