#include "../inc.h"


int** subset(int n, int* nums, int numsSize, int** columnSizes, int* returnSize) {

	if(n == 0)
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
	
	int *cs, rs, **ret;

	*returnSize = 0;
	for(int i = 0; i <= numsSize; i++) {
		cs = NULL;
		rs = 0;
		subset(i, nums, numsSize, &cs, &rs);
	}
}

int main(int argc, char *argv[])
{
	int *nums, numsSize, **ret, *columnSizes, returnSize;

	if(argc < 2) return -1;

	numsSize = atoi(argv[1]);
	nums = malloc(sizeof(int) * numsSize);

	for(int i = 0; i < numsSize; i++) nums[i] = i;
	
	ret = subsets(nums, numsSize, &columnSizes, &returnSize);	

	for(int i = 0; i < returnSize; i++) {

		for(int j = 0; j < columnSizes[i]; j++)
			printf("%2d ", ret[i][j]);

		printf("\n");
	}
	return 0;
}
