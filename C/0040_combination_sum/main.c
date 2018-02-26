#include "../inc.h"
#include "../sort.h"

int** record(int **result, int *pre, int pn, int** columnSizes, int* returnSize)
{
	if(*returnSize == 0) {
		*columnSizes = malloc(sizeof(int));
		result = malloc(sizeof(int *));
	}
	else {
		*columnSizes = realloc(*columnSizes, sizeof(int) * (*returnSize + 1));
		result = realloc(result, sizeof(int *) * (*returnSize + 1));
	}

	(*columnSizes)[*returnSize] = pn;
	result[*returnSize] = malloc(sizeof(int) * pn);
	for(int i = 0; i < pn; i++)
		result[*returnSize][i] = pre[i];

	(*returnSize)++;
	return result;
}

int** dfs(int **result, int *pre, int pn, int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize)
{
	for(int i = 0; i < candidatesSize; i++) {
		
		if(target == 0/*candidates[i]*/) {
			result = record(result, pre, pn, columnSizes, returnSize);
			break;
		}
		else if(target - candidates[i] >= 0){
			int *newPre = malloc(sizeof(int) * (pn + 1));

			for(int k = 0; k < pn; k++) newPre[k] = pre[k];
			newPre[pn] = candidates[i];
			result = dfs(result, newPre, pn + 1, candidates + i + 1, candidatesSize - i - 1, target - candidates[i], columnSizes, returnSize);
			free(newPre);
		}
	}

	return result;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
	
	int **result = NULL;

	*columnSizes = NULL;
	*returnSize = 0;

	if(candidatesSize == 0 || candidates == NULL)
		return NULL;

	bubbleSort(candidates, candidatesSize);
	return dfs(result, NULL, 0, candidates, candidatesSize, target, columnSizes, returnSize);
}

int main() {
	int candidates[] = {10, 1, 2, 7, 6, 1, 5};
	int candidatesSize = 7;
	int target = 8;
	int *columnSizes;
	int returnSize;
	int ** result;
	int i, j;

	result = combinationSum2(candidates, candidatesSize, target, &columnSizes, &returnSize);

	for (i = 0; i < returnSize; i++) {
		int *tmp = result[i];
		for (j = 0; j < columnSizes[i]; j++) {
			printf("%d ", tmp[j]);
		}
		printf("\n");
	}
	return 0;
}
