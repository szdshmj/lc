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
	int blen = (*columnSizes)[bidx], *base = NULL, *tmp, start = 0;
	
	if(bidx != 0) {
		base = ret[bidx]; 
		start = base[blen - 1] + 1;
	}
	
	for(int i = start; i < numsSize; i++) {
		tmp = malloc(sizeof(int) * (blen + 1));	
		if(base)
			memcpy(tmp, base, blen * sizeof(int));

		tmp[blen] = i;
		ret[(*count)] = tmp;
		(*columnSizes)[(*count)] = blen + 1;
		(*count)++;
		#if 0
		for(int i = 0; i < blen + 1; i++)
			printf("%2d ", ret[*count - 1][i]);
		printf("\n");
		#endif
	}

	return numsSize - start;
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	
	int **ret = NULL, ex = 0, count = 1, start = 0, end = 0;

	*returnSize = 0;

	for(int i = 0; i <= numsSize; i++) (*returnSize) += combinNum(numsSize, i);

	ret = malloc(sizeof(int *) * (*returnSize));
	(*columnSizes) = malloc(sizeof(int) * (*returnSize));

	ret[0] = NULL;
	(*columnSizes)[0] = 0;
	if(numsSize == 0) return ret;

	for(int i = 1; i <= numsSize; i++) {

		ex = 0;
		for(int j = start; j <= end; j++)
			ex += expand(ret, j, columnSizes, &count, nums, numsSize);

		start = end + 1;
		end = end + ex;
	}

	for(int i = 0; i < *returnSize; i++)
		for(int j = 0; j < (*columnSizes)[i]; j++)
			ret[i][j] = nums[ret[i][j]];

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
	dump(ret, returnSize, columnSizes);

	return 0;
}
