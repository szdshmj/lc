#include "../inc.h"

void swap(char *a)
{
	int	i = 0, j = strlen(a) - 1;

	while(i < j) {
		int tmp = a[i];

		a[i] = a[j];
		a[j] = tmp;
		i++, j--;
	}
}

int add_bit(char *c, int i, int shift)
{
	int ret = 0;

	if(c[i] > 1) {
		c[i] -= 2;
		ret = 1;
	}
	c[i] += '0';

	return ret;
}

char* _addBinary(char* a, char* b) {

	int i, shift = 0, al = strlen(a), bl = strlen(b);
	char *c;

	if(al > bl)
		return _addBinary(b, a);

	c = calloc(sizeof(char), bl + 2);

	for(i = 0; i < al; i++) {

		c[i] = a[i] - '0' + b[i] - '0' + shift;
		shift = add_bit(c, i, shift);
	}

	for(; i < bl; i++) {

		c[i] = b[i] - '0' + shift;
		shift = add_bit(c, i, shift);
	}

	if(shift == 1) c[i] = '1';

	swap(c);

	return c;
}

char* addBinary(char* a, char* b) {

	if(a != NULL && b != NULL) {
		swap(a),swap(b);
		return _addBinary(a, b);
	}
	else if(a == NULL)
		return b;
	else
		return a;
}

int main()
{
	char a[] = "1111", b[] = "1111";	

	printf("%s\n", addBinary(a, b));
}
