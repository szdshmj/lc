#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
	
	if(nums == NULL || numsSize == 0)
		return 0;

	for(int i = 0; i < numsSize; i++) {

		if(nums[i] != val)
			continue;
#if 0
		for(int j = i + 1; i < numsSize; j++)
			nums[j - 1] = nums[j];	
#else
		nums[i] = nums[numsSize - 1];
#endif

		numsSize--;
		i--;
	}
	return numsSize;
}

int main()
{
	int a[] = {3, 2, 2, 3};

	int n = removeElement(a, sizeof(a) / sizeof(a[0]), 3);

	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
