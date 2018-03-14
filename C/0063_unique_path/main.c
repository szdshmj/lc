#include "../inc.h"

void shift(int *a, int *b, int is_dec)
{
	int tmp = *a;	

	tmp = (is_dec == 1) ? tmp - 1: tmp + 1;
	*a = *b;
	*a = (is_dec == 1) ? *a - 1: *a + 1;
	*b = tmp;
}

void rotaion(int **obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize, int is_dec)
{
	int r = obstacleGridRowSize / 2, c = obstacleGridColSize / 2;

	for(int i = 0; i < r; i++)
		for(int j = 0; j < obstacleGridColSize; j++)
			shift(&obstacleGrid[i][j], &obstacleGrid[obstacleGridRowSize - 1 - i][obstacleGridColSize - 1 - j], is_dec); 

	if(obstacleGridRowSize & 0x01) {

		for(int i = 0, j = obstacleGridColSize - 1; i < j; i++, j--)
			shift(&obstacleGrid[r][i], &obstacleGrid[r][j], is_dec);

		if(obstacleGridColSize & 0x01)
			obstacleGrid[r][c] = (is_dec == 1) ? obstacleGrid[r][c] - 1 : obstacleGrid[r][c] + 1;
	}
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {

	int ret = 0;
	if(obstacleGrid == NULL || obstacleGridRowSize < 1 || obstacleGridColSize < 1) goto out;

	//dump_int_int_m_n(obstacleGrid, obstacleGridRowSize, obstacleGridColSize);
	rotaion(obstacleGrid, obstacleGridRowSize, obstacleGridColSize, 1);
	//dump_int_int_m_n(obstacleGrid, obstacleGridRowSize, obstacleGridColSize);

	for(int i = 0; i < obstacleGridColSize; i++) {

		if(obstacleGrid[0][i] == -1)
			obstacleGrid[0][i] = 1;
		else {
			i++;
			while(i < obstacleGridColSize) obstacleGrid[0][i++] = 0;
		}

	}
	for(int i = 1; i < obstacleGridRowSize - 1; i++) {

		if(obstacleGrid[i][0] == -1)
			obstacleGrid[i][0] = 1;
		else {
			i++;
			while(i < obstacleGridRowSize) obstacleGrid[i++][0] = 0;
		}
	}

	for(int i = 0; i < obstacleGridRowSize; i++) {
		for(int j = 0; j < obstacleGridColSize; j++) {

			if(obstacleGrid[i][j] == -1)
				obstacleGrid[i][j] = (i - 1 < 0 ? 0 : obstacleGrid[i - 1][j])  + (j - 1 < 0 ? 0 : obstacleGrid[i][j - 1]);
		}
	}

	ret = obstacleGrid[obstacleGridRowSize - 1][obstacleGridColSize - 1];
	//dump_int_int_m_n(obstacleGrid, obstacleGridRowSize, obstacleGridColSize);

out:
	return ret;
}

int main(int argc, char **argv)
{
#if 0
	int a[][3] = {
		{0, 0, 0},
		{0, 1, 0},
		{0, 0, 0}
	};
#elif 0
	int a[][5] = {
		{0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0}
	};

#elif 0
	int a[][6] = {
		{1, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 0, 0}
	};
#elif 0

	int a[][1] = {
		{0},
		{1}
	};
#elif 0
	int a[][1] = {
		{0},
	};
#else
	int a[][1] = {
		{0},
		{0},
	};
#endif

	int i, j, k = 3;
	int row_size = atoi(argv[1]);
	int col_size = atoi(argv[2]);
	int **grids = malloc(row_size * sizeof(int *));

	if (argc < 3) {
		fprintf(stderr, "Usage: ./test m n\n");
		exit(-1);
	}

	for (i = 0; i < row_size; i++) {
		grids[i] = malloc(col_size * sizeof(int));
		for (j = 0; j < col_size; j++)
			grids[i][j] = 
#if 0
				i * col_size + j + 1;
#else
		a[i][j];
#endif
	}

	printf("%d\n", uniquePathsWithObstacles(grids, row_size, col_size));
	return 0;
}
