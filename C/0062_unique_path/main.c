#include "../inc.h"

int uniquePaths(int m, int n) {

	int *a = calloc(sizeof(int), m * n), ret;

	for(int i = 0; i < m; i++)
		a[i * n] = 1;

	for(int j = 0; j < n; j++)
		a[j] = 1;

	for(int i = 1; i < m; i++)
		for(int j = 1; j < n; j++)
			a[i * n + j] = a[i * n + j - 1] + a[(i - 1) *n +j];
	
	ret = a[(m - 1) * n + n - 1];
	free(a);
	return ret;
}

int main()
{
	printf("%d\n", uniquePaths(3, 3));
}
