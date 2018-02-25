#include "../inc.h"
#include <limits.h>
#include "../sort.h"

void dump(int *nums, int numsSize)
{
	for(int i = 0; i < numsSize; i++)
		printf("%d ", nums[i]);

	printf("\n");
}

void nextPermutation(int* nums, int numsSize) {

	int mark = -1;

	for(int i = numsSize - 1; i > 0; i--) {
		if(nums[i] > nums[i - 1]) {
			mark = i - 1;
			break;
		}
	}

	if(mark != -1) {
		
		int i = mark + 1, tmp;
		while(nums[i] > nums[mark] && i < numsSize)
			i++;

		i--;

		tmp = nums[i];
		nums[i] = nums[mark];
		nums[mark] = tmp;
		
	}

	bubbleSort(&nums[mark + 1], numsSize - 1 - mark);
}



int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[] = {4, 7, 2, 1, 5, 9, 3, 6, 8};
	int c[] = {1, 6, 3, 4, 5, 7, 9, 8, 2};
	int d[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	printf("-=-=-=-=-=-=a-=-=-=-=-=-=-=\n");
	dump(a, sizeof(a) / sizeof(a[0]));
	nextPermutation(a, sizeof(a) / sizeof(a[0]));
	dump(a, sizeof(a) / sizeof(a[0]));
	printf("-=-=-=-=-=-=b-=-=-=-=-=-=-=\n");
	dump(b, sizeof(b) / sizeof(b[0]));
	nextPermutation(b, sizeof(b) / sizeof(b[0]));
	dump(b, sizeof(b) / sizeof(b[0]));
	printf("-=-=-=-=-=-=c-=-=-=-=-=-=-=\n");
	dump(c, sizeof(c) / sizeof(c[0]));
	nextPermutation(c, sizeof(c) / sizeof(c[0]));
	dump(c, sizeof(c) / sizeof(c[0]));
	printf("-=-=-=-=-=-=d-=-=-=-=-=-=-=\n");
	dump(d, sizeof(d) / sizeof(d[0]));
	nextPermutation(d, sizeof(d) / sizeof(d[0]));
	dump(d, sizeof(d) / sizeof(d[0]));

	return 0;
}
