#include<stdio.h> 

long long reverse(long long x){
	int max = 0x7fffffff, min = 0x80000000;
	int digit, flag = 1;
	long long result = 0;
	if (x < 0)
	{
		flag = -1;
		x = -x; 
	} 
	while(x)
	{
		digit = x % 10;
		result = result * 10 + digit;
		x /= 10;
	}
	if(flag == -1) result = -result;
	return (result>max||result<min)?0:result;
}

int main()
{
	long long num = reverse(1534236469);
	printf("%lld", num);
	return 0;
}
