#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** threeSum2(int* nums, int numsSize, int* returnSize) {

	int **p = NULL, count = 0;

	for(int i = 0; i < numsSize - 2; i++) {

		for(int j = i + 1; j < numsSize - 1; j++) {
			
			for(int k = j + 1; k < numsSize; k++) {
					
				if(nums[i] + nums[j] + nums[k] == 0) {
					
					//printf("%d, %d, %d\n", nums[i], nums[j], nums[k]);
					int a = num[i], b = num[j], c = num[k], has = 0;

						
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
							p = realloc(p, count + 1);

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
	else
		p = threeSum2(nums, numsSize, returnSize);

	return p;
}

int main()
{
	int a[] = {-1, 0, 1, 2, -1, -4}, **p, s;
	p = threeSum(a, sizeof(a) / sizeof(a[0]), &s);

	for(int i = 0; i < s; i++) {
//		printf("%d, %d, %d\n", p[i][0], p[i][1], p[i][2]);
	}
}
