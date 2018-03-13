#include "../inc.h"

void dumps(char ***ret, int count, int n)
{
	char **m;
	for(int i = 0; i < count; i++) {

		printf("matrix %d:\n", i);

		m = ret[i];

		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++)
				printf("%c", m[j][k]);
			printf("\n");
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

char** buildMatrix(int **matrix, int n)
{
	char **cmatrix = malloc(sizeof(char *) * n);

	for(int i = 0 ; i < n; i++) {
		cmatrix[i] = calloc(sizeof(char) , n + 1);
		for(int j = 0; j < n; j++)
			cmatrix[i][j] = (matrix[i][j] == 1 ? 'Q' : '.');
	}

	return cmatrix;
}

void addMatrix(char ****ret, char **cmatrix, int *returnSize)
{
	if(*ret == NULL)
		*ret = malloc(sizeof(char ***));
	else
		*ret = realloc(*ret, (*returnSize + 1) * sizeof(char **));

	(*ret)[*returnSize] = cmatrix;
	(*returnSize)++;
}

void dfs(char ****ret, int **matrix, int n, int r, int *returnSize)
{
	if(r == n)
		return addMatrix(ret, buildMatrix(matrix, n), returnSize);

	for(int c = 0; c < n; c++) {

		if(checkMatrix(matrix, n, r, c) == true) {

			matrix[r][c] = 1;
			dfs(ret, matrix, n, r + 1, returnSize);
			matrix[r][c] = 0;
		}
	}
}

char*** solveNQueens(int n, int* returnSize) {
	
	int **matrix = malloc(sizeof(int *) * n);
	char ***ret = NULL;

	*returnSize = 0;
	for(int i = 0; i < n; i++) matrix[i] = calloc(sizeof(int), n);

	dfs(&ret, matrix, n, 0, returnSize);

	//dumps(ret, *returnSize, n);
	return ret;
}

int main(int argc, char *argv[])
{
	int n = 8, returnSize;

	if(argc > 1)
		n = atoi(argv[1]);

	solveNQueens(n, &returnSize);
	return 0;
}
