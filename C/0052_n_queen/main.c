#include "../inc.h"

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

int totalNQueens(int n) {

	int **matrix = malloc(sizeof(int *) * n), count = 0 ;

	for(int i = 0; i < n; i++) matrix[i] = calloc(sizeof(int), n);

	dfs(matrix, n, 0, &count);
	return count;
}

int main(int argc, char *argv[])
{
	int n = 8;

	if(argc > 1)
		n = atoi(argv[1]);

	totalNQueens(n);
	return 0;
}
