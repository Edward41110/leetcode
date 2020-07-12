#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
	bool isAllNine = true;
	int i;
	int* retArray;
	for(i = 0;i < digitsSize;i++)
		if (digits[i] != 9)
		{
			isAllNine = false;
			break;
		}
	if (isAllNine)
	{
		retArray = (int*)malloc(sizeof(int) * (*returnSize = digitsSize + 1));
		retArray[0] = 1;
		for(i = 1;i < *returnSize;i++)
			retArray[i] = 0;
	}
	else
	{
		bool carry = false;
		retArray = (int*)malloc(sizeof(int) * (*returnSize = digitsSize));
		retArray[digitsSize - 1] = digits[digitsSize - 1] + 1;
		for (i = digitsSize - 2;i >= 0;i--)
		{
			if (retArray[i + 1] == 10)
			{
				retArray[i + 1] = 0;
				carry = true;
			}
			if(carry)
			{
				retArray[i] = digits[i] + 1;
				carry = false;
			}
			else retArray[i] = digits[i];
		}
		
	}
	return retArray;
}

int main()
{
	int returnSize;
	int digits[] = {9, 8, 9, 9};
	int* retArray = plusOne(digits, sizeof(digits)/sizeof(digits[0]), &returnSize); 
	
	int i;
	for(i = 0;i < returnSize;i++)
		printf("%d ", retArray[i]);
	free(retArray);
	return 0;
}
