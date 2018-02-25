#incldue "../inc.h"

int binarySearch(int *nums, int numsSize, int target)
{
	int l = 0, r = numsSize - 1, mid = -1;

	while(l <= r) {

		mid = l + ((r - l) >> 1);
		printf("target %d nums[mid] %d\n", target, nums[mid]);
		if(target > nums[mid]) 
			l = mid + 1;
		else if(target <= nums[mid])
			r = mid - 1;
	}
	printf("l %d, r %d\n", l, r);
	return l - 1;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize) {

	int idx, i, *p = malloc(sizeof(int) * 2);

	*returnSize = 2;
	p[0] = -1;
	p[1] = -1;
	if(!nums || numsSize < 1)
		return p;

	if(numsSize == 1) {
		if(target == nums[0]) {
			p[0] = 0;
			p[1] = 0;
		}
		return p;
	}

	idx = binarySearch(nums, numsSize, target);	

	printf("idx %d\n", idx);
	if(idx < 0 || idx >= numsSize || nums[idx] != target) {
		p[0] = -1;
		p[1] = -1;
		return p;
	}

	for(i = idx; i < numsSize; i++) {
		if(nums[i] > target)
			break;
	}//start idx, end i - 1

	p[0] = idx;

	if(idx == i - 1)
		p[1] = idx;
	else	
		p[1] = i - 1;

	return p;
}

int main()
{
	//int a[] = {5, 7, 7, 8, 8, 10}, targe = 8, s, *p;
	//int a[] = {1}, target = 1, s, *p;
	//int a[] = {3, 3, 3}, target = 3, s, *p;
	int a[] = {-2, -1}, target = 0, s, *p;

	p = searchRange(a, sizeof(a) / sizeof(a[0]), target, &s);

#if 1
	for(int i = 0; i < s; i++)
		printf("%d ", p[i]);

	printf("\n");
#endif
}
