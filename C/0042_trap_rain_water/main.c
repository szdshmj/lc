#include "../inc.h"

int findABowl(int *height, int heightSize, int *r)
{
	int result = 0, left = 0;

	while(left + 1 < heightSize && height[left + 1] > height[left]) left++;

	*r += (left + 1);

	while(*r < heightSize && height[*r] < height[left])
		(*r)++;

	if(*r < heightSize) {
		
		for(int i = left + 1; i < *r; i++)
			result += (height[left] - height[i]);
	}
	
	return result;
}

int trap(int* height, int heightSize) {

	int l = 0, width = 0, result = 0;
	
	while(height[l] == 0 && heightSize > 0) {
		height++;
		heightSize--;
	}
	
	while(l < heightSize) {

		width = 0;
		int bowl = findABowl(height + l, heightSize - l, &width);

		if(bowl > 0) {
			result += bowl;
			l += width;
		}
		else
			l++;
	}

	return result;
}

int main()
{
	//int ret, a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int ret, a[] = {4, 2, 3};

	ret = trap(a, sizeof(a) / sizeof(a[0]));
	printf("%d\n", ret);

	return 0;
}
