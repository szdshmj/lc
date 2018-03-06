#include "../inc.h"

void dump(int** matrix, int m, int n) {

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

void rotate_positive_90(int** matrix, int n, int *matrixColSizes) {

	for(int i = 0; i < n -1; i++) {
		
		for(int j = i; j < n - 1 - i; j++) {
			
			int tmp = matrix[i][j];	
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
			matrix[n - 1 - i][n - 1 -j] = matrix[j][n - 1 - i];
			matrix[j][n - 1 - i] = tmp;
		}
	}
}

void rotate_positive_180(int** matrix, int n, int *matrixColSizes)
{
	for(int i = 0; i < n / 2; i++) {
		
		for(int j = 0; j < n; j++) {

			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - i][ n - 1 - j];
			matrix[n - 1 - i][ n - 1 - j] = tmp;
		}
	}
}

void rotate_negtive_90(int** matrix, int n, int *matrixColSizes)
{
	
}

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes)
{
	rotate_positive_90(matrix, matrixRowSize, matrixColSizes);
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
	rotate_positive_90(a, n, NULL);
	dump(a, n, n);
	return 0;
	rotate_positive_90(a, n, NULL);
	dump(a, n, n);
	rotate_positive_90(a, n, NULL);
	//dump(a, n, n);
	rotate_positive_90(a, n, NULL);
	//dump(a, n, n);
	rotate_positive_180(a, n, NULL);
	dump(a, n, n);

	/*free ......
	  for()
	  free
	  free
	 */
	return 0;
}
