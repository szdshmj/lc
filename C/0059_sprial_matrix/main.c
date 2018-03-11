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

int** generateMatrix(int n) {

	int minRow = 0, minCol = 0, maxRow = n, maxCol = n, direct = 0, r = 0, c = 0, count = 1;

	if(n = 0) return NULL;

	matrix = malloc(sizeof(int *) * n);
	for(int i = 0; i < n; i++)
		matrix[i] = malloc(sizeof(int) * n);

	matrix[0][0] = 1;

	while(count < n * n) {

		next(matrix, &minRow, &minCol, &maxRow, &maxCol, &r, &c, &direct);
		matrix[r][c] = ++count;
	}
	return matrix;
}

int main(int argc, char *argv[])
{
	int **matrix, n = 3;
	
	if(argc > 1)
		n = atoi(argv[1]);	

	matrix = generateMatrix(n);

//	return 1;
	for(int i = 0; i < n; i++) {

		for(int j = 0; j < n; j++)
			printf("%2d ", matrix[i][j]);

		printf("\n");
	}

	return 0;
}
