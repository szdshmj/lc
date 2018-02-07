#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** exhaustion(int* nums, int numsSize, int* returnSize) {

	int **p = NULL, count = 0;

	for(int i = 0; i < numsSize - 2; i++) {

		for(int j = i + 1; j < numsSize - 1; j++) {
			
			for(int k = j + 1; k < numsSize; k++) {
					
				if(nums[i] + nums[j] + nums[k] == 0) {
					
					//printf("%d, %d, %d\n", nums[i], nums[j], nums[k]);
					int a = nums[i], b = nums[j], c = nums[k], t, has = 0;

					if(a > b) {t = a; a = b; b = t;}
					if(b > c) {t = b; b = c; c = t;}
					if(a > b) {t = a; a = b; b = t;}

					for(int m = 0; m < count; m++) {
						if(p[m][0] == a && p[m][1] == b && p[m][2] == c) {
							has = 1;
							break;
						}
					}
					if(count == 0 || has == 0) {

						int *arr = malloc(sizeof(int) * 3);

						arr[0] = a;
						arr[1] = b;
						arr[2] = c;
						if(count == 0)
							p = malloc(sizeof(int *));
						else
							p = realloc(p, sizeof(int *) * count + 1);

						p[count++] = arr;
					}
					if(has == 1)
						has = 0;
				}
			}
		}
	}

	*returnSize = count;
	return p;
}

void bubbleSort(int *a, int numsSize)
{
	int ex = 1, last = numsSize - 1;

	for(int i = 0; i < numsSize - 1 && ex; i++) {
		
		ex = 0;
		for(int j = 0; j < last; j++) {
			
			if(a[j + 1] < a[j]) {

				int t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
				ex = j;
			}
		}
		last = ex;
	}

#if 0
	printf("[ ");
	for(int i = 0; i < numsSize; i++)
		printf("%d ", a[i]);
	printf("]\n");
#endif
}

int** threeSumByOrder(int* nums, int numsSize, int* returnSize) {

	int **p = NULL, count = 0, l, r, target = 0;

	if(nums[0] > 0 || nums[numsSize -1] < 0)
		return p;

	for(int i = 0; i < numsSize - 2; i++) {

		if(nums[i] > 0)
			break;

		if(i > 0 && nums[i] == nums[i - 1])
			continue;
		
		l = i + 1;
		r = numsSize - 1;

		while(l < r) {

			int sum = nums[l] + nums[r] + nums[i];
			if(sum == target ) {

				int *arr = malloc(sizeof(int) * 3);

				arr[0] = nums[i];
				arr[1] = nums[l];;
				arr[2] = nums[r];;
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
			else if(sum < target)
				l++;
			else if(sum > target)
				r--;
		}
	}
	*returnSize = count;
	return p;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {

	int **p = NULL;

	if(returnSize == NULL)
		returnSize = calloc(sizeof(int), 1);

	if(nums == NULL || numsSize < 3)
		return p;

	if(numsSize == 3) {
		if(nums[0] + nums[1] + nums[2] == 0) {

			p = malloc(sizeof(int *));	
			p[0] = malloc(sizeof(int) * 3);
			for(int i = 0; i < 3; i++)
				p[0][i] = nums[i];

			*returnSize = 1;
		}
	}
	else {
#if 0
		p = exhaustion(nums, numsSize, returnSize);
#else
		bubbleSort(nums, numsSize);
		p = threeSumByOrder(nums, numsSize, returnSize);
#endif
	}

	return p;
}

int main()
{
	//int a[] = {-1, 0, 1, 2, -1, -4}, **p, s = 0;
	int a[] = {1, 2, -2 , -1}, **p, s = 0;

	p = threeSum(a, sizeof(a) / sizeof(a[0]), &s);

	for(int i = 0; i < s; i++)
		printf("%d, %d, %d\n", p[i][0], p[i][1], p[i][2]);

	return 0;
}
