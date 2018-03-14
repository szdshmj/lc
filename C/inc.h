#ifndef __LEET_CODE_COMM_H__
#define __LEET_CODE_COMM_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __cplusplus
	#define bool int
	#define true 1
	#define false 0
#endif

static void dump_int_n(int *nums, int numsSize)
{
	for(int i = 0; i < numsSize; i++)
		printf("%2d ", nums[i]);

	printf(".\n");
}

static void dump_int_m_n(int *a, int m, int n)
{
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", *(a + n * i + j));
		printf("\n");
	}

	printf("..\n");
}

static void dump_int_int_m_n(int **matrix, int m, int n)
{
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}

	printf("..\n");
}

static void dump_char_m_n(char *board, int boardRowSize, int boardColSize) {

	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++)
			printf("'%c', ", *(board + 9 * i + j));
		printf("\n");
	}

	printf("..\n\n");
}

static void dump_char_char_char(char ***ret, int returnSize, int *columnSizes) {

	for(int i = 0; i < returnSize; i++) {
		for(int j = 0; j < columnSizes[i]; j++)
			printf("%s ", ret[i][j]);
		printf("\n");
	}

	printf("..\n\n");
}
#endif
