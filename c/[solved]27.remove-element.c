//¿ìÂıÖ¸Õë·¨ 

#include <stdio.h> 

int removeElement(int* nums, int numsSize, int val){
	int slow = 0, quick = 0;
	for (;quick < numsSize;quick++)
		if (nums[quick] != val)
			nums[slow++] = nums[quick];
	return slow;
} 

int main()
{
	int i;
	int a[] = {3, 2, 2, 3};
	int len = removeElement(a, sizeof(a)/sizeof(a[0]), 3);
	for (i = 0;i < len;i++)
		printf("%d ", a[i]);
	return 0;
}

