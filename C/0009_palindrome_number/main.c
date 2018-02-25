#include "../inc.h"
#include <limits.h>

int a[] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10};
bool isPalindrome(int x) {
	
	unsigned int step;

	if(x < 0)
		return false;

	if(x < 10)
		return true;

	for(step = 0; step < sizeof(a) / sizeof(a[0]); step++) {

		if(x / a[step] != 0)
			break;
	}	

	for(unsigned int i = step; i < sizeof(a) / sizeof(a[0]); i += 2) {

		int m = x % 10;
		int n = x / a[i];	

		printf("m %d, n%d\n", m, n);
		if(m != n)
			return false;

		x = x % a[i];
		x = x / 10;

		if(x == 0)
			return true;

		if(x < 10) {
			if(a[i] > 100)
				return false;
			else
				return true;
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	bool r = isPalindrome(atoi(argv[1]));

	if(r == true)
		printf("true\n");
	else
		printf("false\n");

	return 0;
}
