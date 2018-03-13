#include "../inc.h"

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {

}

int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: ./test m n\n");
		exit(-1);
	}

	int i, j, k = 3;
	int row_size = atoi(argv[1]);
	int col_size = atoi(argv[2]);
	int **grids = malloc(row_size * sizeof(int *));
	for (i = 0; i < row_size; i++) {
		grids[i] = malloc(col_size * sizeof(int));
		int *line = grids[i];
		for (j = 0; j < col_size; j++) {
			line[j] = atoi(argv[k++]);
			printf("%d ", line[j]);
		}
		printf("\n");
	}
	printf("%d\n", uniquePathsWithObstacles(grids, row_size, col_size));
	return 0;
}
