#include "../inc.h"

bool dfs(int *nums, int numsSize)
{
	if(numsSize == 1)
		return true;

	if(nums[0] == 0)
		return false;

	for(int i = 1; i <= nums[0]; i++) {
		 bool ret = dfs(nums + i, numsSize - i);			
		 if(ret == true)
			 return ret;
	}

	return false;
}

bool canJump(int* nums, int numsSize) {

	if(nums == NULL || numsSize == 0)
		return false;

	if(numsSize == 1)
		return true;
#if 1
	int mark = numsSize - 1;
	for(int i = numsSize - 1; i >= 0; i--) {

		if(nums[i] + i >= mark)
			mark = i;
	}
	return mark == 0;
#else
	return dfs(nums, numsSize);		
#endif
}

int main()
{
//	int a[] = {2,3,1,1,4};
//	int a[] = {3,2,1,0,4};
	int a[] = {2,0,0};
	
	printf("%d\n", canJump(a, sizeof(a) / sizeof(a[0])));
}
