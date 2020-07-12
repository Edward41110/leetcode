#include <stdio.h> 

int searchInsert(int* nums, int numsSize, int target) {
	if (numsSize == 0 || target <= nums[0]) return 0;
	if (target > nums[numsSize - 1])  return numsSize;
	if (target == nums[numsSize - 1]) return numsSize - 1;
	int i, front = 0, last = numsSize - 1;
	int location = (last - front) / 2;
	
	while (1)
	{
		if (target > nums[location])
		{
			front = location + 1;
			location = (last - front) / 2;
		}
		else
			if (target > nums[location - 1]) return location;
			else
			{
				last = location - 1;
				location = (last - front) / 2;
			}
	}
}

int main()
{
	int a[] = { 1, 3, 5, 6 };
	printf("%d\n", searchInsert(a, sizeof(a) / sizeof(a[0]), 4));
	return 0;
}

