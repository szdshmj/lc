#include "../inc.h"

void dump(int **ret, int returnSize, int *columnSizes)
{
	for(int i = 0; i < returnSize; i++) {

		for(int j = 0; j < columnSizes[i]; j++)
			printf("%2d ", ret[i][j]);

		printf("\n");
	}
}

int expand(int **ret, int bidx, int **columnSizes, int *count, int *nums, int numsSize)
{
	int blen = (*columnSizes)[bidx], *base = ret[bidx], *tmp, c = 0;
	
	for(int i = base[blen - 1] + 1; i < numsSize; i++) {
		tmp = malloc(sizeof(int) * (blen + 1));	
		memcpy(tmp, base, blen * sizeof(int));

		tmp[blen] = i;
		ret[(*count)] = tmp;
		(*columnSizes)[(*count)] = blen + 1;
		(*count)++;
		for(int i = 0; i < blen + 1; i++)
			printf("%2d ", ret[*count - 1][i]);
			printf("\n");
		c++;
	}

	return c;
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	
	int **ret = NULL, ex = 0, count = 0, start = 1, end = numsSize;

	*returnSize = 0;

	for(int i = 0; i <= numsSize; i++) (*returnSize) += combinNum(numsSize, i);

	ret = malloc(sizeof(int *) * (*returnSize));
	(*columnSizes) = malloc(sizeof(int) * (*returnSize));

	ret[0] = NULL;
	(*columnSizes)[0] = 0;
	if(numsSize == 0) return ret;


	for(int i = 0; i < numsSize; i++) {
		ret[i + 1] = malloc(sizeof(int));
		ret[i + 1][0] = i;
		(*columnSizes)[i + 1] = 1;
	}

	count = numsSize + 1;
	for(int i = 2; i <= numsSize; i++) {

		ex = 0;
		for(int j = start; j <= end; j++)
			ex += expand(ret, j, columnSizes, &count, nums, numsSize);

		if(ex > 0) {
			start = end + 1;
			end = end + ex;
		}
	}

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
