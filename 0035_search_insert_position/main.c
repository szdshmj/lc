#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {

	int l = 0, r = numsSize - 1, m;
	
	if(nums == NULL || numsSize < 1)
		return 0;

	if(numsSize == 1) {
		if(nums[0] < target)
			return 1;
		else
			return 0;
	}

	if(nums[0] >= target)
		return 0;
	if(nums[numsSize - 1] == target)
		return numsSize -1;
	if(nums[numsSize - 1] < target)
		return numsSize;
	
	while(l <= r) {
	
		m = l + (r - l) / 2;

		if(target == nums[m])
			return m;
		else if(target < nums[m])
			r = m - 1;
		else
			l = m + 1;
	}
	
	return l;	
}

int main()
{
	int a[] = {1, 3, 5, 6}, target[4] = {5, 2, 7, 0};
	
	for(int i = 0; i < 4; i++) {
		
		int n = searchInsert(a, sizeof(a) / sizeof(a[0]), target[i]);
	printf("%d\n", n);
	}
}
