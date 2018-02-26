#include <limits.h>
#include "../inc.h"
#include "../sort.h"

int** record(int **result, int** columnSizes, int* returnSize, int *pre, int n)
{
	if(*returnSize == 0) {
		*columnSizes = malloc(sizeof(int));
		result = (int **)malloc(sizeof(int *));
	}
	else {
		*columnSizes = (int *)realloc(*columnSizes, sizeof(int) * (*returnSize + 1));
		result = (int **)realloc(result, sizeof(int *) * (*returnSize + 1));
	}
	
	(*columnSizes)[*returnSize] = n;
	result[*returnSize] = (int *) malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) result[*returnSize][i] = pre[i];
	(*returnSize)++;

	return result;
}

int** dfs(int **result, int *pre, int pn, int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {

	int *newPre;

	for(int i = 0; i < candidatesSize; i++) {
		for(int j = 1; candidates[i] * j <= target; j++) {

			int leftSize = candidatesSize - i - 1;

			if(leftSize < 0) continue;

			newPre = malloc((pn + j) * sizeof(int));
			for(int k = 0; k < pn; k++) newPre[k] = pre[k];
			for(int k = 0; k < j; k++) newPre[k + pn] = candidates[i];

			if(target - candidates[i] * j > 0)
				result = dfs(result, newPre, pn + j, candidates + i + 1, leftSize, target - candidates[i] * j, columnSizes, returnSize);
			else
				result = record(result, columnSizes, returnSize, newPre, pn + j);
			//free(newPre);
		}
	}
	return result;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {

	int **result = NULL;

	*columnSizes = NULL;	
	*returnSize = 0;

	if(candidatesSize < 1 || candidates == NULL)
		return NULL;

	bubbleSort(candidates, candidatesSize);

	return dfs(result, NULL, 0, candidates, candidatesSize, target, columnSizes, returnSize);
}

int main() {
	int candidates[] = {2, 3, 6, 7};
	int candidatesSize = 4;
	int target = 7;
	int *columnSizes;
	int returnSize;
	int ** result;
	int i, j;

	result = combinationSum(candidates, candidatesSize, target, &columnSizes, &returnSize);

	for (i = 0; i < returnSize; i++) {
		int *tmp = result[i];
		for (j = 0; j < columnSizes[i]; j++) {
			printf("%d ", tmp[j]);
		}
		printf("\n");
	}
	return 0;

}
