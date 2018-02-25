#include "../inc.h"

int maxArea(int* height, int heightSize) {

	int max = 0, left = 0, right = heightSize - 1;

	if(height == NULL || heightSize < 2)
		return 0;

	if(heightSize == 2)
		return height[0] < height[1]? height[0]:height[1];

	while(left < right) {

		int small, area;

		if(height[left] == 0) {
			left++;
			continue;
		}

		if(height[right] == 0) {
			right--;
			continue;
		}
		small = (height[left] < height[right] ? height[left] : height[right]);
		area = small * (right - left);

		if(max < area)
			max = area;

		if(height[left] < height[right])
			left++;
		else
			right--;
	}
	//printf("max %d\n", max);    
	return max;
}

int main(int argc, char *argv[])
{
	int a[] = {6,14,2,11,2,7,0,9,12,7};
	maxArea(a, sizeof(a) / sizeof(a[0]));
}
