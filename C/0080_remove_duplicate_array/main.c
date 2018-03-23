#include "../inc.h"
int removeDuplicates(int* nums, int numsSize) {

	int i = 0,j, diff, c = 0, *nnums;

	if(numsSize == 0 || numsSize == 1) return numsSize;

	nnums = malloc(sizeof(int) * numsSize);

	for(j = 1; j < numsSize; j++) {

		if(nums[i] == nums[j]) continue;

		if(j - i > 1) 
			nnums[c++] = nums[i];

		nnums[c++] = nums[i];
		i = j;
	}

	diff = numsSize - i;
	if(diff > 2) diff = 2;

	for(int i = 0; i < diff; i++)
		nnums[c++] = nums[numsSize - 1];

	for(int i = 0; i < c; i++)
		nums[i] = nnums[i];

	free(nnums);
	return c;
}
