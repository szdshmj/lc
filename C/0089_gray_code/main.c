#include "../inc.h"

int* grayCode(int n, int* returnSize) {

	int *ret = NULL;

	*returnSize = 1 << n;

	ret = malloc(sizeof(int) * *returnSize);
#if 0
	ret[0] = 0;

	if(*returnSize == 1)
		goto out;

	ret[1] = 1;

	for(int i = 2, c = 2; c < *returnSize; i = i * 2) {

		for(int j = i - 1; j >= 0; j--)
			ret[c++] = i + ret[j];
	}
#else
	for(int i = 0; i < *returnSize; i++)
		ret[i] = (i >> 1) ^ i;
#endif
out:
	return ret;

}
int main(int argc, char *argv[])
{
	int *list, returnSize;	

	list = grayCode(atoi(argv[1]), &returnSize);
	dump_int_n(list, returnSize);

	return 0;
}
