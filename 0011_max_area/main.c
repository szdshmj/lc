#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) {
	
	int max = 0, left = 0, right = heightSize - 1;

	if(height == NULL || heightSize < 2)
		return 0;

	for(int i = 0; i < heightSize; i++)
		if(height[i] < 1)
			return 0;

	if(heightSize == 2)
		return height[0] < height[1]? height[0]:height[1];
	
	while(left < right) {

		int small = (height[left] < height[right] ? height[left] : height[right]);
		int area = small * (right - left);

		if(max < area)
			max = area;

		if(height[left] < height[right])
			left++;
		else
			right--;
	}
	printf("max %d\n", max);	
	return max;
}

int main(int argc, char *argv[])
{
	int a[] = {1, 1};
	maxArea(a, 2);
}
