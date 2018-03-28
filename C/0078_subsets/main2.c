#include "../inc.h"

void dfs(int* nums, int numsSize, int** columnSizes, int* returnSize, int *buf, int pos, int start, int **ret) {

	if(pos > 0) {
		ret[*returnSize] = malloc(sizeof(int) * pos);
		for(int i = 0; i < pos; i++)
			ret[*returnSize][i] = buf[i];
		(*columnSizes)[*returnSize] = pos;
	}
	else {
		ret[*returnSize] = NULL;
		(*columnSizes)[*returnSize] = 0;
	}

	(*returnSize)++;

	for(int i = start; i < numsSize; i++) {

		buf[pos] = nums[i];
		dfs(nums, numsSize, columnSizes, returnSize, buf, pos + 1, i + 1, ret);
	}
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {

	int capacity = 5000;
	int buf[numsSize];
	int **ret = malloc(capacity * sizeof(int *));

	*columnSizes = malloc(capacity * sizeof(int));
	*returnSize = 0;

	dfs(nums, numsSize, columnSizes, returnSize, buf, 0, 0, ret);

	return ret;
}

int main(int argc, char *argv[])
{
	int *nums, numsSize, **ret = NULL, *columnSizes, returnSize, i = 0;

	if(argc < 2) return -1;

	numsSize = atoi(argv[1]);
	nums = malloc(sizeof(int) * numsSize);
	for(i = 0; i < numsSize; i++) nums[i] = i + 1;

	ret = subsets(nums, numsSize, &columnSizes, &returnSize);	
	//dump(ret, returnSize, columnSizes);

	return 0;
}
