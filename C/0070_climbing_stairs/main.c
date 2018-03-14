#include "../inc.h"

int climbStairs(int n) {
	
	int ret, *a = calloc(n + 1, sizeof(int));
	
	a[n] = 1;
	a[n - 1] = 2;

	for(int i = n - 2; i > 0; i--)
		a[i] = a[i + 1] + a[i + 2];

	ret = a[1];
	free(a);

	return ret;
}

int main(int argc, char *argv[])
{
	return printf("%d\n", climbStairs(atoi(argv[1])));
}
