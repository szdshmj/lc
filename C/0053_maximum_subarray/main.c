#include "../inc.h"
#include "limits.h"

int maxSubArray(int* nums, int numsSize) {

	int sum = nums[0], tmp_sum = nums[0];

	for(int i = 1; i < numsSize; i++) {

		if(nums[i] > sum && sum < 0) {
			sum = nums[i];
			tmp_sum = nums[i];
			continue;
		}

		if(tmp_sum <= 0 && nums[i] > 0)
			tmp_sum = nums[i];
		else
			tmp_sum = tmp_sum + nums[i];

		if(tmp_sum >= sum)
			sum = tmp_sum;
		else if(tmp_sum < 0) 
			tmp_sum = 0;
	}

	return sum;
}

int main()
{
	//int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	//int a[] = {-2, 1};
	int a[] = {-2, -1};

	printf("maxsubarray is %d\n", maxSubArray(a, sizeof(a) / sizeof(a[0])));
}
