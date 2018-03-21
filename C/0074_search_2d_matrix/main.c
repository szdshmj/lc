#include "../inc.h"

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {

	int total = matrixRowSize * matrixColSize, *line, c = 0, i, j, mid;
	bool ret = false;

	if(total == 0) return false;

	line = malloc(sizeof(int) * total);

	for(int i = 0; i < matrixRowSize; i++)
		for(int j = 0; j < matrixColSize;j++)
			line[c++] = matrix[i][j];

	i = 0, j = total - 1;
	while(i <= j) {

		mid = i + (j - i) / 2;
		if(line[mid] == target) {
			ret = true;
			break;
		}
		else if(line[mid] > target)
			j = mid - 1;
		else
			i = mid + 1;
	}

	free(line);
	return ret;
}
