//¿ìÂıÖ¸Õë·¨ 

#include<stdio.h> 

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize < 2) return numsSize;
	int quick = 1, slow = 1;
	while (quick < numsSize)
	{
		if (nums[quick] != nums[slow - 1])
			nums[slow++] = nums[quick];
		quick++;
	}
	return slow;
}

int main()
{
	int a[] = { 1, 2 };
	int len = removeDuplicates(a, sizeof(a)/sizeof(a[0]));
	int i;
	for (i = 0;i < len;i++)
		printf("%d ", a[i]);
	getchar();
	return 0;
}

