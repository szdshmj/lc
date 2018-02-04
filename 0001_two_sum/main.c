#include <stdio.h>
#include <sting.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) 
{
	int *p = NULL;

	if(numsSize < 2 || nums == NULL)
		return NULL;

	for(int i = 0; i < numsSize - 1; i++) {
		for(int j = i + 1; j < numsSize; j++) {
		
			if(nums[i] + nums[j] == target) {
				p = malloc(sizeof(int) * 2);	
				p[0] = i;
				p[1] = j;
				return p;
			}
		}	
	}
	return NULL;
}
