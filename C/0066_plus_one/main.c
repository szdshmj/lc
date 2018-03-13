#include "../inc.h"

int* plusOne(int* digits, int digitsSize, int* returnSize) {

	int *ret, i = 0, j = digitsSize - 1, shift = 1;

	if(digits == NULL || digitsSize < 1)
		return NULL;

	ret = calloc(sizeof(int), digitsSize + 1);

	while(i < j) {

		ret[digitsSize - 1 - i] = digits[i];
		ret[digitsSize - 1 - j] = digits[j];
		
		i++;
		j--;
	}

	if(i == j)
		ret[i] = digits[i];

	i = 0;
	while(shift == 1) {
		
		ret[i] += shift;
		if(ret[i] > 9) {
			shift = 1;
			ret[i++] -= 10;
		}
		else
			shift = 0;
	}

	if(ret[digitsSize] != 0) 
		*returnSize = digitsSize + 1; 
	else
		*returnSize = digitsSize; 

	i = 0, j = *returnSize - 1;
	
	while(i < j) {

		int tmp = ret[i];
		ret[i] = ret[j];
		ret[j] = tmp;
		
		i++;
		j--;
	}
	
	return ret;
}

int main()
{
	int a[] = {1, 0}, returnSize;

	plusOne(a, 2, &returnSize);
}
