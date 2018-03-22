#include "../inc.h"


int** subset(int n, int* nums, int numsSize, int** columnSizes, int* returnSize) {

	int **ret;
	if(n == 0) {
		
		*returnSize = 1;
		ret = malloc(sizeof(int *));	
		ret[0] = NULL;
	}
	else if(n == 1) {
		*returnSize = numsSize;
		ret = malloc(sizeof(int *) * numsSize);	
		*columnSizes = malloc(sizeof(int) * numsSize);

		for(int i = 0; i < numsSize; i++) {
			ret[i] = malloc(sizeof(int));
			ret[i][0] = nums[i];
			(*columnSizes)[i] = 1;
		}

	}
	else if(n == numsSize) {
		*returnSize = 1;
		ret = malloc(sizeof(int *));	
		*columnSizes = malloc(sizeof(int));
		(*columnSizes)[0] = numsSize;
		
		ret[0] = malloc(sizeof(int) * numsSize);

		for(int i = 0; i < numsSize; i++)
			ret[0][i] = nums[i];	

	}
	else {
	}
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
	int *nums, numsSize, **ret, *columnSizes, returnSize, i, j;

	if(argc < 2) return -1;

	numsSize = atoi(argv[1]);
	nums = malloc(sizeof(int) * numsSize);

	while(i < numsSize) nums[i] = ++i;
	
	ret = subsets(nums, numsSize, &columnSizes, &returnSize);	

	for(i = 0; i < returnSize; i++) {

		for(j = 0; j < columnSizes[i]; j++)
			printf("%2d ", ret[i][j]);

		printf("\n");
	}

	return 0;
}
