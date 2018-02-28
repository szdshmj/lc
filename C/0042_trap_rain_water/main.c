#include "../inc.h"

void dump(int *height, int heightSize)
{
	printf("t %d\n", heightSize);
	for(int i = 0; i < heightSize; i++)
		printf("%d ", height[i]);
	printf("\n");
}

int newRight(int s, int *height, int heightSize)
{
	int mark = -1;

	for(int i = 0; i < heightSize; i++) {
		if(height[i] >= s)
			mark = i;		
	}

	//printf("can forward %d\n", mark + 1);
	return mark + 1;
}

int findABowl(int *height, int heightSize, int *result)
{
	int left = 0, buttom, right = - 1, pos, skip = 0;

	while(left + 1 < heightSize && height[left + 1] > height[left]) left++;

	pos = left + 1;
	buttom = pos;

	while(pos < heightSize && height[pos] <= height[buttom]) {

		if(height[pos] < height[buttom]) {
			buttom = pos;
		}
//		printf("buttom a[%d] = %d\n", buttom, height[buttom]);
		if(height[pos + 1] > height[pos]) {
			right = pos + 1;
		}
		pos++;
	}

	while(right + 1 < heightSize && height[right + 1] > height[right])	right++;
//	printf("left %d, right %d, \n", left, right);
	
	if(right + 1 < heightSize && height[right] < height[left])
		skip = newRight(height[right], height + right + 1, heightSize - right - 1);

	right = skip > 0 ? right + skip : right;

	if(right < heightSize) {

		int minH = height[left] < height[right] ? height[left] : height[right];

		for(int i = left + 1; i < right; i++) {
			if(minH > height[i]) {
				*result += (minH - height[i]);
//				printf("\t\t\tresult %d\n", *result);
			}
		}
		return right;
	}
	else
		return -1;
}

int trap(int* height, int heightSize) {

	int l = 0, width = 0, result = 0;

	while(l < heightSize) {

		//printf("new l %d.................\n", l);
		if((width = findABowl(height + l, heightSize - l, &result)) > 0)
			l += width;
		else
			break;
	}

	return result;
}

int main()
{
	//int ret, a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	//int ret, a[] = {4, 2, 3};
	//int ret, a[] = {5, 4, 1, 2};
	//int ret, a[] = {5,2,1,2,1,5};
	int ret, a[] = {5,5,1,7,1,1,5,2,7,6};

	ret = trap(a, sizeof(a) / sizeof(a[0]));
	printf("%d\n", ret);

	return 0;
}
