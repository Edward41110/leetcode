#include <stdio.h>

double myPow(double x, int n){
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1/x;
    double half = myPow(x, n/2);
    double rest = myPow(x, n%2);
    double total = half * half * rest;
    return total;
}

int main()
{
	double result = myPow(-2, 2);
	printf("%f\n", result);
	return 0;
}
