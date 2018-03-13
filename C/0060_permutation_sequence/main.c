#include "../inc.h"

int compare(const void *a, const void *b)
{
	return (char *)a < (char *)b;
}

int genNext(char *n, int len)
{
	for(int i = len; i > 0; i--) {

		if(n[i] < n[i - 1]) continue;

		for(int j = len, tmp; j >= i; j--) {
			if(n[j] < n[i - 1]) continue;

			tmp = n[j];
			n[j] = n[i - 1];
			n[i - 1] = tmp;
			break;
		}

		if(len - i > 0)
			qsort(n + i, len - i + 1, sizeof(char), &compare);
		return 1;
	}
	return 0;
}

char* getPermutation(int n, int k) {

	char *c = malloc(sizeof(char) * (n + 1));

	c[n] = '\0';
	for(int i = 0; i < n; i++)
		c[i] = i + '1';

	int i = 1, next = 1;
	while(i++ < k && next == 1)
		next = genNext(c, n - 1);

	return c;
}

int main(int argc, char *argv[])
{
#if 0
	char n[] = "123";
	
	int i = 0;
	do {
		printf("%s\n", n);
		genNext(n, strlen(n) - 1);
	}
	while(++i < 6);
#else
	if(argc > 2)
		printf("%s\n", getPermutation(atoi(argv[1]), atoi(argv[2])));
#endif
	return 0;
}
