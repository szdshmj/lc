#include "../inc.h"

double fast_pow(double x, int n)
{
	if (n == 1 || n == -1) return x;
	if (n == 0) return 1.0;
	double t = fast_pow(x, n / 2);
	return n & 1 ? t * t * x : t * t;
}

double myPow(double x, int n)
{
	double t = fast_pow(x, n);
	return n < 0 ? 1 / t : t;
}

int main()
{
	printf("%f\n", myPow(5, -1));
	return 0;
}
