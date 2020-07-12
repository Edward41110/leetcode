#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* getRow(int numRows, int* returnSize) {
	numRows++;
	*returnSize = numRows;
	int **ret = (int **)malloc(sizeof(int *) * numRows);
	int i;
	for (i = 0;i < numRows;i++)
	{
		ret[i] = (int *)malloc(sizeof(int) * (i + 1));
		ret[i][0] = ret[i][i] = 1;
		int j;
		for (j = 1;j < i;j++)
			ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
	}
	return ret[numRows - 1];
}

int main()
{
	int numRows = 5;
	int returnSize;
	int *ret = getRow(numRows, &returnSize);
	printf("returnSize = %d\n", returnSize);
	int i;
	for (i = 0;i < numRows;i++)
		printf("%d\t", ret[i]);
	printf("\n");
	getchar();
	return 0;
}
