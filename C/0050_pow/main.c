#include "../inc.h"
double fast_pow(double x, int n)
{
    if (n == 0) { return 1.0; }
    if (n == 1) { return x; }
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
	printf("%f\n", myPow(1.00000, -2147483648));
	return 0;
}
