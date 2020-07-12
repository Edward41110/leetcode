#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	*returnSize = numRows;
	*returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
	int **ret = (int **)malloc(sizeof(int *) * numRows);
	int i;
	for (i = 0;i < numRows;i++)
	{
		(*returnColumnSizes)[i] = i + 1;
		ret[i] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[i]);
		ret[i][0] = ret[i][i] = 1;
		int j;
		for (j = 1;j < i;j++)
			ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
	}
	return ret;
}

int main()
{
	int numRows = 15;
	int returnSize;
	int *returnColumnSizes;
	int **ret = generate(numRows, &returnSize, &returnColumnSizes);
	printf("returnSize = %d\n", returnSize);
	int i;
	for (i = 0;i < numRows;i++)
	{
		printf("returnColumnSizes = %d\n", returnColumnSizes[i]);
		int j;
		for (j = 0;j < returnColumnSizes[i];j++)
			printf("%d\t", ret[i][j]);
		printf("\n");
	}
	getchar();
	return 0;
}
