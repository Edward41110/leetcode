#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize)
{
	if (numsSize < 2) return true;
	if (numsSize >= 2 && !nums[0]) return false;
	int i;
	for (i = numsSize - 1;i >= 0;i--)
	{
		if (i == numsSize - 1 && nums[i] == 0)
		{
			i--;
			while (nums[i] < numsSize - i - 1)
				if (i) i--;
				else if (!i && nums[i] < numsSize - 1) return false;
		}
		else if (nums[i] == 0)
		{
			int j = i;
			while (1)
			{
				if (nums[i] > (j - i)) break;
				if (i) i--;
				if (!i && nums[i] <= j) return false;
			}
		}
	}
	return true;
}

int main()
{
	int nums[] = {3, 2, 1, 0, 4};
	bool can = canJump(nums, sizeof(nums)/sizeof(nums[0]));
	printf("%d\n", can);
	return 0;
}
