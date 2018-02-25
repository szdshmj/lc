#include "../inc.h"
#include "../sort.h"

int** fourSumByOrder(int* nums, int numsSize, int target, int* returnSize) {

	int **p = NULL, count = 0, l, r, ntarget;

	for(int i = 0; i < numsSize - 3; i++) {
		
		while(i > 0 && nums[i] == nums[i - 1]) {i++; continue;}
		ntarget = target - nums[i];
		for(int j = i + 1; j < numsSize - 2; j++) {

			//printf("i %d, j %d, nums[j] %d, nums[j - 1] %d\n", i, j, nums[j], nums[j - 1]);
			while((j > i + 1) && (nums[j] == nums[j - 1])) {j++; continue;}
			l = j + 1;
			r = numsSize - 1;

			while(l < r) {

				int sum = nums[l] + nums[r] + nums[j];
				if(sum == ntarget ) {

					int *arr = malloc(sizeof(int) * 4);

					arr[0] = nums[i];
					arr[1] = nums[j];
					arr[2] = nums[l];;
					arr[3] = nums[r];;
					if(count == 0)
						p = malloc(sizeof(int *));
					else
						p = realloc(p, sizeof(int *) * count + 1);

					p[count++] = arr;

					while(nums[l] == nums[l + 1] && l < r) l++;
					while(nums[r] == nums[l - 1] && l < r) r--;

					l++;
					r--;
				}
				else if(sum < ntarget)
					l++;
				else if(sum > ntarget)
					r--;
			}
		}
	}
	*returnSize = count;
	return p;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize) {

	int **p = NULL;

	if(returnSize == NULL)
		returnSize = calloc(sizeof(int), 1);

	if(nums == NULL || numsSize < 4)
		return p;

	if(numsSize == 4) {
		if(nums[0] + nums[1] + nums[2] + nums[3] == target) {

			p = malloc(sizeof(int *));	
			p[0] = malloc(sizeof(int) * 4);
			for(int i = 0; i < 4; i++)
				p[0][i] = nums[i];

			*returnSize = 1;
		}
	}
	else {

		bubbleSort(nums, numsSize);
		p = fourSumByOrder(nums, numsSize, target, returnSize);
	}

	return p;
}

int main()
{
	int a[] = {-1, 0, 1, 2, -1, -4}, **p, s = 0, t = -1;
	//int a[] = {1, 0, -1, 0, -2, 2}, **p, s = 0;

	p = fourSum(a, sizeof(a) / sizeof(a[0]), t, &s);

	for(int i = 0; i < s; i++)
		printf("%d, %d, %d, %d\n", p[i][0], p[i][1], p[i][2], p[i][3]);

	return 0;
}
