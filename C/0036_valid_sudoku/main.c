#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValidSudoku2(char **board, int r, int c)
{
	int tmp[9];

	for(int t = 0; t < 9; t++) tmp[t] = 0;
	for(int i = 0; i < 3; i++) {
		
		for(int j = 0; j < 3; j++) {
			
			if(board[r + i][c + j] != '.') {
				int n = board[r + i][c + j] - '1';
				if(tmp[n] == 1) 
					return false;
				else
					tmp[n] = 1;
			}
		}
	}
	return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {

	int tmp[9];

	if(board == NULL)
		return false;

	for(int i = 0; i < 9; i++) {
		
		for(int t = 0; t < 9; t++) tmp[t] = 0;
		
		for(int j = 0; j < 9; j++) {
			
			if(board[i][j] != '.') {
					
				int n = board[i][j] - '1';

				if(tmp[n] == 1) 
					return false;
				else
					tmp[n] = 1;
			}
		}
	}

	for(int i = 0; i < 9; i++) {
		
		for(int t = 0; t < 9; t++) tmp[t] = 0;

		for(int j = 0; j < 9; j++) {

			if(board[j][i] != '.') {
				int n = board[j][i] - '1';

				if(tmp[n] == 1) 
					return false;
				else
					tmp[n] = 1;
			}
		}
	}

	/*[0, 0], [0, 3], [0, 6]
	[3, 0], [3, 3], [3, 6]
	[6, 0], [6, 3], [6, 6]*/

	for(int i = 0; i < 9; i += 3) {

		for(int j = 0; j < 9; j += 3) {

			if(isValidSudoku2(board, i, j) == false)
				return false;
		}
	}

	return true;
}
