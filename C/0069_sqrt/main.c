#include "../inc.h"
#if 1
int mySqrt(int x) {

	int l = 1, r = x / 2, mid;

	  if(x < 1) return 0;
    if(x < 4) return 1;
    if(x < 9) return 2;
	mid = l + (r - l) / 2;

	while(l <= r) {
		if(mid == x /mid) return mid;
		else if(mid > x / mid)
			r = mid - 1;
		else
			l = mid + 1;
		mid = l + (r - l) / 2;
	}
//	return r;
}
#else
int mySqrt(int x) {
	if (x <= 0) return 0;
	int left = 1, right = x, mid = left + (right - left) / 2;
	while (left <= right) {
		if (mid == x / mid) return mid;
		else {
			if (mid > x / mid) right = mid - 1;
			else left = mid + 1;
			mid = left + (right - left) / 2;
		}
	}
	return right;
}
#endif
int main(int argc, char *argv[])
{
	printf("%d\n", mySqrt(atoi(argv[1])));
}
