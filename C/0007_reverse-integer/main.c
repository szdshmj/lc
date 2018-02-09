#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

const int limit = INT_MAX / 10;

int reverse(int x) {

	int total = 0;

	while(x != 0) {

		int a = x % 10;
		x = x / 10;

		if(total > limit || total < -limit) return 0;

		total = 10 * total + a;
	}

	return total;
}

int main(int argc, char *argv[])
{
	printf("%d\n", reverse(atoi(argv[1])));
	return 0;		
}
