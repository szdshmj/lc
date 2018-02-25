#include "../inc.h"

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
			for(int k = 1; k < 10; k++) {
				//printf("%d(%d) ", tmp[k],k);

				if(tmp[k] == 0)
					printf("%d ", k);
			}

			printf("\n");
		}
}

void opCo(int *co[][9], int boardRowSize, int boardColSize, int flag)
{
	for(int i = 0; i < boardRowSize; i++)
		for(int j = 0; j < boardColSize; j++)
			if(flag == 0)
				co[i][j] = (int *)calloc(sizeof(int), 10);
			else
				free(co[i][j]);
}

void mark(int *tmp, char v)
{
	if(v != '.')
		tmp[v - '0'] = 1;
}

void updateCo(char **board, int boardRowSize, int boardColSize, int row, int col, int *tmp)
{
	int r = row - row % 3, c = col - col % 3;

	tmp[0] = 1;
	for(int i = 0; i < boardColSize; i++) {

		if(i == col) continue;
		mark(tmp, board[row][i]); 
	}

	for(int i = 0; i < boardRowSize; i++) {

		if(i == row) continue;
		mark(tmp, board[i][col]); 
	}

	for(int i = r; i < r + 3; i++) {
		for(int j = c; j < c + 3; j++) {

			if(r == row && c == col) continue;
			mark(tmp, board[i][j]); 
		}
	}
}

void updateCos(char** board, int boardRowSize, int boardColSize, int *co[][9]) 
{
	for(int i = 0; i < boardRowSize; i++) {

		for(int j = 0; j < boardColSize; j++) {

			if(board[i][j] == '.') 
				updateCo(board, boardRowSize, boardColSize, i, j, co[i][j]);
			else
				for(int k = 0; k < 10; k++)
					co[i][j][k] = 1;
		}
	}
	//dumpCo(co);
}

int tryKatIJ(char** board, int boardRowSize, int boardColSize, int i, int j, int k)
{
	int tmp[10];

	for(int z = 0; z < 10; z++) tmp[z] = 0;
	updateCo(board,boardRowSize, boardColSize, i, j, tmp);
	return (tmp[k] == 0) ? 0 : -1;
}

int solveSudoku2(char** board, int boardRowSize, int boardColSize, int i, int j, int *co[][9])
{
	if(j == boardColSize) {
		if(++i == boardRowSize)
			return 0;
		j = 0;
	}

	if(board[i][j] == '.') {
		for(int k = 1; k < 10; k++) {

			if((co[i][j][k] == 1) || (tryKatIJ(board, boardRowSize, boardColSize, i, j, k) != 0))
				continue;

			board[i][j] = k + '0';
			if(solveSudoku2(board, boardRowSize, boardColSize, i, j + 1, co) == 0)
				return 0;
			board[i][j] = '.';
		}
		return -1;
	}
	else 
		return solveSudoku2(board, boardRowSize, boardColSize, i, j + 1, co);
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {

	int* co[9][9];

	if(board == NULL) return;
	
	opCo(co, boardRowSize, boardColSize, 0);
	updateCos(board, boardRowSize, boardColSize, co);

	solveSudoku2(board, boardRowSize, boardColSize, 0, 0, co);
	opCo(co, boardRowSize, boardColSize, 1);
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
