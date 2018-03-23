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

int *make_int_m(int m)
{
	int *data = (int *)calloc(m, sizeof(int));
	return data;
}

int **make_int_int_m_n(int m, int n, int *a)
{
	int **data = (int **)malloc(m * sizeof(int *));

	for (int i = 0; i < m; i++) {
		data[i] = (int *)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
			data[i][j] = *(a + i * n + j);
	}

	return data;
}

void dump_int_n(int *nums, int numsSize)
{
	for(int i = 0; i < numsSize; i++)
		printf("%2d ", nums[i]);

	printf(".\n");
}

void dump_int_m_n(int *a, int m, int n)
{
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", *(a + n * i + j));
		printf("\n");
	}

	printf("..\n");
}

void dump_int_int_m_n(int **matrix, int m, int n)
{
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}

	printf("..\n");
}

void dump_char_m_n(char *board, int boardRowSize, int boardColSize) {

	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++)
			printf("'%c', ", *(board + 9 * i + j));
		printf("\n");
	}

	printf("..\n\n");
}

void dump_char_char_char(char ***ret, int returnSize, int *columnSizes) {

	for(int i = 0; i < returnSize; i++) {
		for(int j = 0; j < columnSizes[i]; j++)
			printf("%s ", ret[i][j]);
		printf("\n");
	}

	printf("..\n\n");
}

int combinNum(int m, int n)
{
    int a = 1, b = 1;

    if(m - n > n) n = m - n;
    for(int i = m; i > n; i--) a *= i;
    for(int i = m - n; i > 1; i--) b *= i;

    return a / b;
}

#endif
