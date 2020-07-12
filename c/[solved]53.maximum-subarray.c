#include <stdio.h> 

//正数增益法 

int maxSubArray(int *nums, int numsSize) {
	if (numsSize == 1) return nums[0];
	int now, max = nums[0], i;
	int AllNegative = 1;
	for(i = 0;i < numsSize;i++)
	{
		if (nums[i] > max)
			max = nums[i];
		if (nums[i] >= 0)
		{
			AllNegative = 0;
			break;
		}
	}
	if (AllNegative) return max;
	now = max = 0;
	for (i = 0;i < numsSize;i++)
	{
		now = now + nums[i];
		if (now < 0)
			now = 0;
		if (now > max)
			max = now;
	}
	return max;
}

int main()
{
	int nums[] = {-2,1};
	printf("%d\n",maxSubArray(nums, sizeof(nums)/sizeof(nums[0])));
	return 0;
}

