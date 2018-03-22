#include "../inc.h"

int** merge(int **org, int *returnSize, int **tmp, int tmpSize, int n, int cSize)
{
	int **ret;

	ret = malloc(sizeof(int *) * (*returnSize + tmpSize));

	for(int i = 0; i < *returnSize; i++)
		ret[i] = org[i];

	if(org)
		free(org);

	for(int i = 0; i < tmpSize; i++) {
		ret[*returnSize + i] = malloc(sizeof(int) * (cSize + 1));
		ret[*returnSize + i][0] = n;
		for(int j = 0; j < cSize; j++) {
			ret[*returnSize + i][j + 1] = tmp[i][j];
		}
		free(tmp[i]);
	}

	*returnSize += tmpSize;
	return ret;
}

int** dfs(int n, int k, int* returnSize) {
	
	int **ret = NULL;
	
	if(k == 1) {
		ret = malloc(sizeof(int *) * n);
		for(int i = 0; i < n; i++) {

			ret[i] = malloc(sizeof(int));
			ret[i][0] = i + 1;
		}

		*returnSize = n;
		return ret;
	}
	else {
		
		int **tmp, tmpSize;
		for(int i = n; i >= k; i--) {

			tmpSize = 0;
			tmp = dfs(i - 1, k - 1, &tmpSize);
			
			ret = merge(ret, returnSize, tmp, tmpSize, i, k - 1);
			free(tmp);
		}
	}

	return ret;
}

int** combine(int n, int k, int** columnSizes, int* returnSize) {

	int **ret;

	*returnSize = 0;
	ret = dfs(n, k, returnSize);

#if 0
	*columnSizes = malloc(sizeof(int) * (*returnSize));
	for(int i = 0; i < *returnSize; i++)
		(*columnSizes)[i] = k;
#endif

	return ret;
}

int main(int argc, char *argv[])
{
	int *columnSizes, returnSize, **ret;

	ret = combine(atoi(argv[1]), atoi(argv[2]), &columnSizes, &returnSize);
	
	for(int i = 0; i < returnSize; i++) {
		
		#if 0
		for(int j = 0; j < atoi(argv[2]); j++)
			printf("%2d ", ret[i][j]);

		printf("\n");
		#endif
		free(ret[i]);
	}
	free(ret);
	return 0;
}
