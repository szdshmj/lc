#include "../inc.h"

int compare(const void *a, const void *b) { return (*(int *) a - *(int *)b);}

void dfs(int* nums, int numsSize, int** columnSizes, int* returnSize, int *buf, int pos, int start, int **ret) {

	if(pos > 0) {
		ret[*returnSize] = malloc(sizeof(int) * pos);
		for(int i = 0; i < pos; i++)
			ret[*returnSize][i] = buf[i];
		(*columnSizes)[*returnSize] = pos;
	}
	else {
		ret[*returnSize] = NULL;
		(*columnSizes)[*returnSize] = 0;
	}

	(*returnSize)++;

	for(int i = start, go; i < numsSize; i++) {
		go = 1;
		for(int j = start; j < i && go == 1; j++) {
			if(nums[j] == nums[i])
				go = 0;
		}
		if(go == 0) continue;

		buf[pos] = nums[i];
		dfs(nums, numsSize, columnSizes, returnSize, buf, pos + 1, i + 1, ret);
	}
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {

	int capacity = 5000;
	int buf[numsSize];
	int **ret = malloc(capacity * sizeof(int *));

	qsort(nums, numsSize, sizeof(int), compare);

	*columnSizes = malloc(capacity * sizeof(int));
	*returnSize = 0;

	dfs(nums, numsSize, columnSizes, returnSize, buf, 0, 0, ret);

	return ret;
}

int main(int argc, char **argv)
{
	int i, j;
	if (argc <= 1) {
		fprintf(stderr, "Usage: ./test array...\n");
		exit(-1);
	}
	int size = argc - 1;
	int *nums = malloc(size * sizeof(int));
	for (i = 0; i < size; i++) {
		nums[i] = atoi(argv[i + 1]);
	}
	int *sizes;
	int count;
	int **lists = subsetsWithDup(nums, size, &sizes, &count);
	printf("cc %d\n", count);
	for (i = 0; i < count; i++) {
		for (j = 0; j < sizes[i]; j++) {
			printf("%d ", lists[i][j]);
		}
		printf("\n");
	}
	return 0;
}

