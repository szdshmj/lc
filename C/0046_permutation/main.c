#include "../inc.h"

int factorial(int n)
{
	int f = 1;

	for(int i = n; i > 1; i--)
		f *= i;

	return f;
}

int** permute(int* nums, int numsSize, int* returnSize) {

	int **result = NULL;
	*returnSize = 0;

	if(numsSize > 1) {
		int subReturnSize = 0, **subPermute, acc = -1;
		
		*returnSize = factorial(numsSize);
		result = malloc(*returnSize * sizeof(int *));
		for(int i = 0; i < numsSize; i++) {
			if(i != 0) {
				int tmp = nums[0];
				nums[0] = nums[i];
				nums[i] = tmp;
			}
			subReturnSize = 0;
			subPermute = permute(nums + 1, numsSize - 1, &subReturnSize);
			
			for(int j = 0; j < subReturnSize; j++) {
				result[++acc] = malloc(numsSize * sizeof(int));
				result[acc][0]= nums[0];
				for(int k = 0; k < numsSize - 1; k++)
					result[acc][k + 1] = subPermute[j][k];

				free(subPermute[j]);
			}
			free(subPermute);

			if(i != 0) {
				int tmp = nums[0];
				nums[0] = nums[i];
				nums[i] = tmp;
			}
		}
	}
	else if(numsSize == 1) {
		result = malloc(sizeof(int *));
		result[0] = malloc(sizeof(int));
		result[0][0] = nums[0];
		*returnSize = 1;
	}

	return result;
}

int main(int argc, char *argv[])
{
	int **r, nums[128] = {1, 2, 3, 4, 5, 6, 7, 8}, returnSize, n = 3;

	if(argc > 1)
		n = atoi(argv[1]);
	
	r = permute(nums, n, &returnSize);
	dump_int_int_m_n(r, returnSize, n);

	for(int i = 0; i < returnSize; i++)
		free(r[i]);
	free(r);
	return 0;
}
