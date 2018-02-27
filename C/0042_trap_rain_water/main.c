#include "../inc.h"

int trap(int* height, int heightSize) {
}

int main()
{
	int ret, a[] = {0,1,0,2,1,0,1,3,2,1,2,1};

	ret = trap(a, sizeof(a) / sizeof(a[0]));
	printf("%d\n", ret);

	return 0;
}
