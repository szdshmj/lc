#include "../inc.h"

void dump(int pos, int *nums, int numsSize)
{
	printf("<%d>: ", pos);
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
}

static inline void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int firstMissingPositive(int* nums, int numsSize) {

	int i;

	if(nums == NULL || numsSize < 1)
		return 1;

	for(i = 0; i < numsSize;/* !!! nothing to do*/){

		dump(i, nums, numsSize);

		if(nums[i] - 1 != i && nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) 
			swap(&nums[i], &nums[nums[i] - 1]);
		else
			i++;

	}
	for (i = 0; i < numsSize; i++)
		if (nums[i] != i + 1) break;

	return i + 1;

}


int main()
{
	int a[] = {1,2,0};
	int b[] = {3,4,-1,1};
	int c[] = {1,1};
	int ret;

	ret = firstMissingPositive(a, sizeof(a) / sizeof(a[0]));
	printf("%d\n", ret);

	ret = firstMissingPositive(b, sizeof(b) / sizeof(b[0]));
	printf("%d\n", ret);

	ret = firstMissingPositive(c, sizeof(c) / sizeof(c[0]));
	printf("%d\n", ret);
	return 0;
}
