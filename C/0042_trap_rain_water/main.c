#include "../inc.h"

void dump(int *height, int heightSize)
{
//	printf("t %d\n", heightSize);
	for(int i = 0; i < heightSize; i++)
		printf("%d ", height[i]);
	printf("\n");
}

int newRight(int left, int s, int *height, int heightSize)
{
	int mark = -1, h = s;

	//printf("compare %d,left is %d\n", s, left);
	for(int i = 0; i < heightSize; i++) {
		if(height[i] >= h && h <= left) {
			mark = i;		
			h = height[i];
			//printf("find %d at %d\n", height[i], mark);
		}
	}

	//printf("can forward %d\n", mark + 1);
	return mark + 1;
}

int findABowl(int *height, int heightSize, int *result)
{
	int left = 0, buttom, right = - 1, pos, skip = 0;

	//dump(height, heightSize);
	while(left + 1 < heightSize && height[left + 1] >= height[left]) left++;

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
	//printf("left %d, right %d, \n", left, right);
	
	if(right + 1 < heightSize && height[right] < height[left])
		skip = newRight(height[left], height[right], height + right + 1, heightSize - right - 1);

	right = skip > 0 ? right + skip : right;

	if(right < heightSize) {

		int minH = height[left] < height[right] ? height[left] : height[right];

		for(int i = left + 1; i < right; i++) {
			if(minH > height[i]) {
				*result += (minH - height[i]);
				//printf("\t\t\tresult %d\n", *result);
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

		if((width = findABowl(height + l, heightSize - l, &result)) > 0)
			l += width;
		else
			break;
	}

	return result;
}

int main()
{
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int b[] = {4, 2, 3};
	int c[] = {5, 4, 1, 2};
	int d[] = {5,2,1,2,1,5};
	int e[] = {5,5,1,7,1,1,5,2,7,6};
	int f[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};

	int *p[] = {a, b ,c ,d, e, f}; 
	int s[] = 	{sizeof(a) / sizeof(a[0]), 
				sizeof(b) / sizeof(b[0]), 
				sizeof(c) / sizeof(c[0]), 
				sizeof(d) / sizeof(d[0]),
				sizeof(e) / sizeof(e[0]),
				sizeof(f) / sizeof(f[0]),
				};
	int expect[] = {6, 1, 1, 14, 23, 83};

	for(int i = 0; i < sizeof(p) / sizeof(p[0]); i++){
		printf("do %d\n", i);
		int ret = trap(p[i], s[i]);
		if(ret != expect[i]) {
			printf("index %d is wrong, expect %d, but %d\n", i, expect[i], ret);
			return -1;
		}
	}

	printf("all passd\n");
	return 0;
}
