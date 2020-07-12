#include <stdio.h> 
#include <math.h>

int countPrimes(int n) {
	if (n <= 2) return 0;
	int count = 1;
	int i, j;
	int isPrime = 1;
	for (i = 3;i < n;i += 2)
	{
		for (j = 3;j <= sqrt(i);j += 2)
		{
			if (i % j == 0)
			{
				isPrime = 0;
				break;
			}
		}
		if (isPrime) count++;
		else isPrime = 1;
	}
	return count;
}

int main()
{
	printf("%d", countPrimes(20));
	return 0;
}

