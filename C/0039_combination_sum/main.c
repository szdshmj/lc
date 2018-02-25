#include <limits.h>
#include "../inc.h"
#include "../sort.h"

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {

	int **result = NULL;

	if(candidatesSize == 1) {
		if(candidates[0] != target) {

			*columnSizes = NULL;	
			*returnSize = 0;
			return NULL;
		}	
		else {
			*columnSizes = (int *)malloc(sizeof(int));
			*columnSizes[0] = 1;
			result = (int**) malloc(sizeof(int *));
			result[0] = (int *) malloc(sizeof(int));
			result[0][0] = target;
			*returnSize = 1;	
			return result;
		}
	}
	else {
		int returnSize_;
		int *columnSizes_ = NULL;
		int **sub;

		for(int i = 0; i < candidatesSize; i++) {
			for(int j = 0; j < INT_MAX; j++) {
				if(candidates[i] * j < target) {

					returnSize_ = 0;
					columnSizes_ = NULL;
					if(candidatesSize - i - 1 > 0)
						sub = combinationSum2(candidates + i + 1, candidatesSize - i - 1, target - candidates[i] * j, &columnSizes_, &returnSize_);

					if(sub == NULL) continue;


				}
			}
		}
	}

	return result;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {

	*columnSizes = NULL;	
	*returnSize = 0;

	if(candidatesSize < 1 || candidates == NULL)
		return NULL;

	bubbleSort(candidates, candidatesSize);

	return combinationSum2(candidates, candidatesSize, target, columnSizes, returnSize);
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
		for (j = 0; j < columnSizes[i]; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}
