#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	int sign = 0, result = 0;
	unsigned int udivisor, udividend;

	if((divisor == 0) || (divisor == -1 && dividend == INT_MIN))
		return INT_MAX;

	if(divisor == 1)
		return dividend;

	sign = (dividend ^ divisor) >> ((sizeof(int) << 3) - 1);
	udivisor = (divisor < 0) ? -divisor : divisor;
	udividend = (dividend < 0) ? -dividend : dividend;

	while(udividend >= udivisor) {

		int i = max_i(udividend, udivisor);

		udividend -= (udivisor << i);

		if(i > 0)
			result += (1 << i);
		else
			result++;
	}
	return (sign == 0) ? result : -result;
}

int divide2(int dividend, int divisor) {
	//special cases
	if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
		return INT_MAX;

	// transform to unsigned int
	bool sign = (dividend > 0)^(divisor > 0);
	unsigned int A = (divisor < 0) ? -divisor : divisor;
	unsigned int B = (dividend < 0) ? -dividend : dividend;
	int ret = 0;

	// shift 32 times
	for(int i = 31; i >= 0; i--)
	{
		if((B>>i) >= A)
		{
			ret = (ret<<1)|0x01;
			B -= (A<<i);   // update B
		}
		else
			ret = ret<<1;
	}

	if(sign)
		ret = -ret;

	return ret;
}

int main()
{
	int i = divide(INT_MIN, 2);
	printf("%d\n", i);
	return 0;
}
