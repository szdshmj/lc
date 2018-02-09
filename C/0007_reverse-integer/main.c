#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int limit = INT_MAX / 10;
const int limit_p = INT_MAX % 10;
const int limit_n = 0 - INT_MIN % 10;

int reverse(int x) {

	int op = 0, total = 0;

	if(x < 10 && x > -10)
		return x;

	if(x < 0) {
		if(x == INT_MIN)
			return 0;
		x = -x;
		op = -1;
	}

	while(x != 0) {

		int a = x % 10;
		x = x / 10;

		if(total > limit) {
			if(op == 0)
				return 0;//INT_MAX;
			else
				return 0;//INT_MIN;
		}

		if(total == limit) {
			if(a > limit_p && op == 0)
				return INT_MAX;
			else if(a > limit_n && op == -1)
				return INT_MIN;
		}

		total *= 10;
		total += a;
	}

	if(op == -1)
		return -total;
	else
		return total;
}

int main(int argc, char *argv[])
{
	printf("%d\n", reverse(atoi(argv[1])));
	return 0;		
}
