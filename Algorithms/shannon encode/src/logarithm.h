#ifndef LOGARITHM_H
#define LOGARITHM_H
#include "stdio.h"

double power(double x, long n); 	/* x^n with x is float, n is interger */
double ln(double x);	/* logarithm of x base e number */
double logarit(double x, double n_base);	/* logarithm of x base n_base */
double abs_f(double x);

double abs_f(double x)
{
	if (x < 0) return -x;
	return x;
}
double power(double x, long n)
{
	if (n == 0) return 1;
	if (n == 1) return x;
	int i;
	double pow = 1;
	for (i=1;i<=n;i++)
		pow *= x;
	return pow;
}

double ln(double x)
{
	int n;
	double loga = 0;
	for(n=1;n<=10000;n++)
		loga += power(-1, n+1) * (power(x-1, n) / n);
	return loga;
}

double logarit(double x, double n_base)
{
	double i = ln(x) / ln(n_base);
	double t = abs_f(i - (double)(int)i);
	if (t < 0.000155)
		return (double)(int)i;
	return  i;
}

#endif