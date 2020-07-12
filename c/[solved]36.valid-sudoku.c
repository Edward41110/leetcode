#include <stdio.h> 
#include <stdbool.h>

bool isValidSudoku(char **board, int boardSize, int boardColSize){
	bool row[9][9] = {0};
	bool col[9][9] = {0};
	bool box[9][9] = {0};
	int i, j;
	for(i = 0;i < 9;i++)
		for(j = 0;j < 9;j++)
		{
			if (board[i][j] < '1' || board[i][j] > '9') continue;
			char num = board[i][j] - '1';
			if (row[i][num] || col[j][num] || box[i/3*3+j/3][num])
				return false;
			row[i][num] = col[j][num] = box[i/3*3+j/3][num] = true;
		}
	return true;
}

int main()
{
	int board[9][9];
	bool isValid = isValidSudoku(board, 81, 9);
	printf("%d\n", isValid);
	return 0;
}
