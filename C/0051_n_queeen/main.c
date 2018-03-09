#include "../inc.h"

void dfs(char **matrix, int n, int r, int c)
{
	if(r == n && c == 0) {

		printf("");
	}
		
}

char*** solveNQueens(int n, int* returnSize) {
	
	int **matrix = malloc(sizeof(int *) * n);

	for(int i = 0; i < n; i++) matrix[i] = calloc(sizeof(int), n);

	dfs(matrix, n, 0, 0);
}

int main()
{
	return 0;
}
