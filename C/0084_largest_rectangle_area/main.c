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

int main()
{
	int a[] = {2,1,5,6,2,3};
	//int a[] = {1,2,3,4,5,6};
	int ret = largestRectangleArea(a, sizeof(a) / sizeof(a[0]));

	printf("%d\n", ret);		

	return 0;
}
