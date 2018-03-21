#include "../inc.h"

void sortColors(int* nums, int numsSize) {
	
	int c[3] = {0,}, p = 0;

	for(int i = 0; i < numsSize; i++)
		c[nums[i]]++;
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < c[i]; j++)
			nums[p++] = i;
	}
}

