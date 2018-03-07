#include "../inc.h"
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
int jump(int *nums, int numsSize)
{
	int *help = malloc(sizeof(int) * numsSize);
	int *step = malloc(sizeof(int) * numsSize);

	for(int i = 0; i < numsSize; i++) help[i] = 0;
	for(int i = 0; i < numsSize; i++) step[i] = 0;

	for(int i = numsSize - 2; i >= 0; i--) {

		if((nums[i] + i) >= numsSize -1) {
			help[i] = 1;
			step
		}
		else {
			
			int next, min = INT_MAX, jj;
			for(int j = 1; j <= nums[i]; j++) {
				
				next = i + j;
				if(help[next] < min) {
					min = help[next];
					jj = j;
				}
			}
			help[i] = min + 1;
		}
	}
	for(int i = 0; i < numsSize; i++) printf("%d ", help[i]);
	printf("\n");
}

int main()
{
	int a[] = {2, 3, 1, 1, 4};

	jump(a, sizeof(a) / sizeof(a[0]));
	return 0;
}
