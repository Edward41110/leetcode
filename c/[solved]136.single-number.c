#include <stdio.h> 
#include <stdbool.h>

int singleNumber(int* nums, int numsSize){
	int i, ret = 0;
	for(i = 0;i < numsSize;i++)
		ret ^= nums[i];
	return ret;
}

int main()
{
	int a[] = {2, 3, 2, 4, 4};
	printf("%d", singleNumber(a, sizeof(a)/sizeof(a[0])));
	return 0;
}

