#include "../inc.h"
#include "../sort.h"
#include <limits.h>
#include <math.h>

int threeSumClosestByOrder(int* nums, int numsSize, int target) {

	int l, r, closest = INT_MAX, diff, diffmax = INT_MAX;

	for(int i = 0; i < numsSize - 2; i++) {

		if(i > 0) while(nums[i] == nums[i - 1] && i < numsSize - 2) i++;

		l = i + 1;
		r = numsSize - 1;

		while(l < r) {

			int sum = nums[i] + nums[l] + nums[r];

			if(sum < target) {
				diff = target - sum;
				while(nums[l] == nums[l + 1]) l++;
				l++;
			}
			else if(sum > target) {
				diff = sum - target;
				while(nums[r] == nums[r - 1]) r--;
				r--;
			}
			else
				return target;

			if(diff < diffmax) {
				diffmax = diff;
				closest = sum;
			}
		}
	}
	return closest;
}

int threeSumClosest(int* nums, int numsSize, int target) {

	if(nums == NULL || numsSize == 0)
		return target;

	if(numsSize <= 3) {
		int s = 0;

		for(int i = 0; i < numsSize; i++)
			s += nums[i];
		return s;
	}
	else {
		bubbleSort(nums, numsSize);
		return threeSumClosestByOrder(nums, numsSize, target);
	}
}

int main()
{
	int a[] = {1, 1, 1, 0}, s = 0;

	s = threeSumClosest(a, sizeof(a) / sizeof(a[0]), 100);

	printf("%d\n", s);
	return 0;
}
