#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize){
    if (numsSize < 2) return false;
	bool ret = false;
	int i, max = nums[0], min = nums[0];
	for (i = 1;i < numsSize;i++)
		if (nums[i] > max) max = nums[i];
		else if (nums[i] < min) min = nums[i];
	int range = max - min + 1;
	if (numsSize > range) return true;
	char* has = (char*)malloc(range);
	for (i = 0;i < range;i++) has[i] = 0;
	for (i = 0;i < numsSize;i++)
		if (has[nums[i] - min] == 0) has[nums[i] - min] = 1;
		else {
			ret = true;
			break;
		}
	free(has);
	return ret;
}

int main()
{
	int nums[] = {1, 2, 3, 4, 1};
	bool isContain = containsDuplicate(nums, sizeof(nums)/sizeof(nums[0]));
	printf("%d\n", isContain);
	return 0;
}
