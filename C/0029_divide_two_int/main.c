#include "../inc.h"
#include <limits.h>

int max_i(int dividend, int divisor)
{
	int i = 1, bits = (sizeof(int) << 3);

	for(i = 1; (i < (bits - 1)) && ((divisor << i) >> bits - 1 == 0) ; i++) {
		
		if((divisor << i) >= dividend)
			return i - 1;
	}
	return i - 1;
}

int divide(int dividend, int divisor) {

	int sign = 0, result = 0, m;
	unsigned int udivisor, udividend, tmp;

	if((divisor == 0) || (divisor == -1 && dividend == INT_MIN)) return INT_MAX;
	if(divisor == 1) return dividend;

	sign = (dividend ^ divisor) >> ((sizeof(int) << 3) - 1);
	udivisor = (divisor < 0) ? -divisor : divisor;
	udividend = (dividend < 0) ? -dividend : dividend;

	while(udividend >= udivisor) {

		tmp = udivisor;
		m = 1;

		while(udividend > (tmp << 1)) {

			tmp <<= 1;
			m <<= 1;	
		}

		udividend -= tmp;
		result += m;
	}
	return (sign == 0) ? result : -result;
}

int main()
{
	int i = divide(INT_MIN, 2);
	printf("%d\n", i);
	return 0;
}
