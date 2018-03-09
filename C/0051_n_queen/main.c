#include "../inc.h"

void dump(int **matrix, int n)
{
	for(int i = 0; i < n; i++) {
		
		for(int j = 0; j < n; j++) {
			
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

bool checkMatrix(int **matrix, int n, int r, int c)
{
	int s = 0;

	for(int i = 0; i < n; i++)	s+= matrix[r][i];

	if(s != 0) return false;

	for(int i = 0; i < n; i++)	s+= matrix[i][c];

	if(s != 0) return false;

	for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) s += matrix[i][j];
	
	if(s != 0) return false;

	for(int i = r + 1, j = c + 1; i < n && j < n; i++, j++)	s += matrix[i][j];

	if(s != 0) return false;

	for(int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) s += matrix[i][j];

	if(s != 0) return false;


	for(int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--) s += matrix[i][j];

	if(s != 0) return false;

	return true;
}

void dfs(int **matrix, int n, int r, int *count)
{
	if(r == n) {

		(*count)++;
		return;
	}

	for(int c = 0; c < n; c++) {

		if(checkMatrix(matrix, n, r, c) == true) {

			matrix[r][c] = 1;
			dfs(matrix, n, r + 1, count);
			matrix[r][c] = 0;
		}
	}
}

char*** solveNQueens(int n, int* returnSize) {
	
	int **matrix = malloc(sizeof(int *) * n), count = 0 ;

	for(int i = 0; i < n; i++) matrix[i] = calloc(sizeof(int), n);

	dfs(matrix, n, 0, &count);
	printf("%d\n", count);
}

int main(int argc, char *argv[])
{
	int n = 8;

	if(argc > 1)
		n = atoi(argv[1]);

	solveNQueens(n, NULL);
	return 0;
}
