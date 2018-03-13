#include "../inc.h"
#include <limits.h>
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

void print(int *next, int *step, int numsSize)
{
	printf("next\n");
	for(int i = 0; i < numsSize; i++) {
		printf("%d ", next[i]);
	}
	printf("\nstep\n");
	for(int i = 0; i < numsSize; i++) {
		printf("%d ", step[i]);
	}
	printf("\n");
}

int jump(int *nums, int numsSize)
{
	int i = 0, j = 0,  min, jj, *next, *step;

	next = calloc(sizeof(int), numsSize);
	step = calloc(sizeof(int), numsSize);

	for(i = numsSize - 2; i >= 0; i--) {

		if(nums[i] == 0) {
			next[i] = INT_MAX;
			step[i] = INT_MAX;
			continue;
		}

		if(nums[i] + i >= numsSize - 1) {
			next[i] = numsSize - 1;
			step[i] = numsSize - 1 - i;
			continue;
		}

		min = INT_MAX - 1;
		jj = INT_MAX;
		for(j = 1; j <= nums[i]; j++) {

			if(next[i + j] < min) {
				min = next[i + j];
				jj = j;
			}
		}
		next[i] = min + 1;
		step[i] = jj;
	}
	
	//print(next, step, numsSize);
	i = 0; j = 0;
	while(i != numsSize -1) { //printf("%d\n", step[i]);

		i += step[i];
		j++;
	}

	free(next);
	free(step);
	return j;
}

int main()
{
//	int a[] = {2, 3, 1, 1, 4};
//	int a[] = {1, 2, 0, 1};
	int a[] = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};

	printf("----%d\n", jump(a, sizeof(a) / sizeof(a[0])));

	return 0;
}
