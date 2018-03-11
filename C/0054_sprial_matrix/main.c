#include "../inc.h"

void next(int** matrix, int *minRow, int *minCol, int *maxRow, int *maxCol, int *r, int *c, int *direct)
{
	if(*direct == 0) {// right		
		if(*c + 1 == *maxCol) {
			(*r)++;
			*direct = 1;
		}
		else
			(*c)++;
	}
	else if(*direct == 1) { //down

		if(*r + 1 == *maxRow) {
			(*c)--;
			*direct = 2;
		}
		else
			(*r)++;
	}
	else if(*direct == 2) {//left
		
		if(*c - 1 < *minCol) {
			(*r)--;
			*direct = 3;
		}
		else
			(*c)--;
	}
	else if(*direct == 3) {//up
	
		if(*r - 1 == *minRow) {
			*direct = 0;
			(*minRow)++;
			*r = *minRow;
			(*minCol)++;
			*c = *minCol;
			(*maxRow)--;
			(*maxCol)--;
		}
		else
			(*r)--;
	}
}

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {

	int i = 0, j = 0, k = 0, *p = NULL, direct = 0, minRow = 0, minCol = 0, maxRow = matrixRowSize, maxCol = matrixColSize;
	
	if(matrix == NULL || matrixRowSize < 1 || matrixColSize < 1)
		goto end;

	p = malloc(sizeof(int) * matrixRowSize * matrixColSize);

	if(matrixRowSize > 1 && matrixColSize > 1) {

		p[k++] = matrix[0][0];
		while(k < matrixRowSize * matrixColSize) {
			next(matrix, &minRow, &minCol, &maxRow, &maxCol, &i, &j, &direct);
			p[k++] = matrix[i][j];
		}
	}
	else if(matrixRowSize == 1) {
		while(k < matrixColSize)
			p[k] = matrix[0][k++];
	}
	else if(matrixColSize == 1) {
		while(k < matrixRowSize)
			p[k] = matrix[k++][0];
	}

end:
	return p;
}

int main(int argc, char *argv[])
{
	int m = 3, n = 4, c = 0, *p, **matrix = malloc(sizeof(int *) * m);

	if(argc > 2) {

		m = atoi(argv[1]);
		n = atoi(argv[2]);
	}

	for(int i = 0; i < m; i++) {

		matrix[i] = malloc(sizeof(int) * n);
		for(int j = 0; j < n; j++)
			matrix[i][j] = ++c;
	}

	p = spiralOrder(matrix, m, n);

	for(int i = 0; i < m * n; i++)
		printf("%d ", p[i]);
	printf("\n");

	return 0;
}
