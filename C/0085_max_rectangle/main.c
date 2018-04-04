#include "../inc.h"

int largestRectangleArea(int* heights, int heightsSize) { // {2,1,5,6,2,3};
	
	int max = 0, top = -1, bar, area, i;
	int *stack = malloc(sizeof(int) * heightsSize);

	for(i = 0; i < heightsSize;) {
		
		if(top == -1 || heights[i] > heights[stack[top]]) {
			stack[++top] = i++;
		}
		else {

			bar = stack[top--];
			area = heights[bar] * (top == -1 ? i : i - stack[top] - 1);

			if(area > max)
				max = area;
		}
	}

	while(top != -1) {

		bar = stack[top--];
		area = heights[bar] * (top == -1 ? i : i - stack[top] - 1);

		if(area > max)
			max = area;
	}

	free(stack);
	return max;
}

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
	
	int *heights = calloc(sizeof(int), matrixColSize), max = 0, tmp;

	for(int i = 0; i < matrixRowSize; i++) {
		
		for(int j = 0; j < matrixColSize; j++)
			
			heights[j] = (matrix[i][j] == '0') ? 0 : heights[j] + 1;
	
		tmp = largestRectangleArea(heights, matrixColSize);	
		if(tmp > max) max = tmp;
	}

	free(heights);
	return max;
}
