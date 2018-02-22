#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dump(char *board, int boardRowSize, int boardColSize) {

	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++)
			printf("'%c', ", *(board + 9 * i + j));
		printf("\n");
	}

	printf("\n\n");
}

void dumpCo(int *co[][9])
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++) {
			int *tmp = co[i][j];

			printf("[%d, %d]: ", i, j);
			for(int k = 0; k < 9; k++) {
				//printf("%d(%d) ", tmp[k],k);
				
				if(tmp[k] == 0)
					printf("%d ", k);
			}

			printf("\n");
		}
}

void updateCo(char **board, int boardRowSize, int boardColSize, int row, int col, int *tmp)
{
	int r = row - row % 3, c = col - col % 3;

	for(int t = 0; t < 9; t++) tmp[t] = 0;

	for(int i = 0; i < 9; i++) {

		if(i == col) continue;
		char c = *((char*)board + row * boardColSize + i); 
		if(c != '.') {
			int n = c - '1';
			tmp[n] = 1;
		}
	}

	for(int i = 0; i < 9; i++) {

		if(i == row) continue;
		char c = *((char*)board + boardColSize * i + col); 
		if(c != '.') {
			int n = c - '1';
			tmp[n] = 1;
		}
	}

	for(int i = r; i < r + 3; i++) {
		for(int j = c; j < c + 3; j++) {

			if(r == row && c == col) continue;

			char c = *((char*)board + i * boardColSize + j); 
			if(c != '.') {
				int n = c - '1';
				tmp[n] = 1;
			}
		}
	}
}

int isSudoku(char **board, int boardRowSize, int boardColSize, int row, int col, int *tmp) 
{
	int correct = -1;

	updateCo(board, boardRowSize, boardColSize, row, col, tmp);

	for(int i = 0; i < 9; i++) {
		if(tmp[i] == 0) {
			if(correct == -1)
				correct = i + 1;
			else {
				correct = -1;
				break;
			}
		}
	}
	
	if(correct != -1) {
		char c = '0' + (char)correct;
		 *((char*)board + row * boardColSize + col) = c; 
		 //printf("[%d, %d] = %c\n", row, col, c);
		return 0;
	}

	return -1;
}

void simplify(char** board, int boardRowSize, int boardColSize, int *co[][9]) {

	int finish = 0;

	while(!finish) {

		finish = 0;
		for(int i = 0; i < boardRowSize; i++) {

			for(int j = 0; j < boardColSize; j++) {

				char c = *((char*)board + boardColSize * i + j); 

				if(c != '.') 
					continue;

				if(isSudoku(board, boardRowSize, boardColSize, i, j, co[i][j]) == -1)
					finish = 1;
				else
					finish = 0;
			}
		}
	}
}

void initCo(char *board, int boardRowSize, int boardColSize, int *co[][9])
{
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			co[i][j] = (int *)calloc(sizeof(int), 9);
			int *tmp = co[i][j];
			for(int k = 0; k < 9; k++) {
				char c = *((char*)board + boardColSize * i + j);
				if(c != '.')
					tmp[k] = 1;
			}
		}
	}
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {

	int* co[9][9];

	if(board == NULL) return;
	
	initCo((char *)board, boardRowSize, boardColSize, co);
	simplify(board, boardRowSize, boardColSize, co);	
	dumpCo(co);

	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++)
			free(co[i][j]);
	}
}

int main()
{
#if 1
	char board[9][9] = {

		{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
		{'7', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '2', '.', '1', '.', '9', '.', '.', '.'},
		{'.', '.', '7', '.', '.', '.', '2', '4', '.'},
		{'.', '6', '4', '.', '1', '.', '5', '9', '.'},
		{'.', '9', '8', '.', '.', '.', '3', '.', '.'},
		{'.', '.', '.', '8', '.', '3', '.', '2', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '6'},
		{'.', '.', '.', '2', '7', '5', '9', '.', '.'}
	};	
#else
	char board[9][9] = {
		{'.', '.', '9', '7', '4', '8', '.', '.', '.',},
		{'7', '.', '.', '.', '.', '.', '.', '.', '.',}, 
		{'.', '2', '.', '1', '.', '9', '.', '.', '.',},
		{'.', '.', '7', '.', '.', '6', '2', '4', '.',},
		{'.', '6', '4', '3', '1', '.', '5', '9', '.',},
		{'.', '9', '8', '.', '.', '.', '3', '.', '.',},
		{'.', '.', '.', '8', '.', '3', '.', '2', '.',},
		{'.', '.', '.', '.', '9', '.', '.', '.', '6',},
		{'.', '.', '.', '2', '7', '5', '9', '.', '.',},
	};
#endif

	//dump((char *) board, 9, 9);
	solveSudoku((char **)board, 9, 9);
	dump((char *) board, 9, 9);
	return 0;
}
