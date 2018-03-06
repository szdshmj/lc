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
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 -j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = tmp;
		}
	}
}

int main(int argc, char *argv[])
{
	int n, **a;
	
	n = atoi(argv[1]);
	a = malloc(sizeof(int *) * n);

	for(int i = 0; i < n; i++) {
		a[i] = malloc(sizeof(int) * n);
		for(int j = 0; j < n; j++) {
			a[i][j] = i * n + j + 1;	
		}
	}

	dump(a, n, n);
	rotate(a, n, NULL);
	dump(a, n, n);
	rotate(a, n, NULL);
	dump(a, n, n);
	rotate(a, n, NULL);
	dump(a, n, n);
	rotate(a, n, NULL);

	/*free ......
	for()
		free
	free
	*/
	return 0;
}
