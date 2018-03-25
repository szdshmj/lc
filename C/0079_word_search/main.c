#include "../inc.h"

bool deep_check(char** board, int boardRowSize, int boardColSize, char* word, int i, int j)
{
    char tmp;

    if(word[0] == '\0') return true;

    if(i < 0 || i >= boardRowSize) return false;
    if(j < 0 || j >= boardColSize) return false;
    if(board[i][j] == '\0') return false;
    if(word[0] != board[i][j]) return false;

	tmp = board[i][j];
	board[i][j] = '\0';
	if(deep_check(board, boardRowSize, boardColSize, word + 1, i, j + 1) == true) return true;
	if(deep_check(board, boardRowSize, boardColSize, word + 1, i + 1, j) == true) return true;
	if(deep_check(board, boardRowSize, boardColSize, word + 1, i, j - 1) == true) return true;
	if(deep_check(board, boardRowSize, boardColSize, word + 1, i - 1, j) == true) return true;
	board[i][j] = tmp;

	return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {

	for(int i = 0; i < boardRowSize; i++) {
		for(int j = 0; j < boardColSize; j++) {

			if(word[0] != board[i][j]) continue;
			if(deep_check(board, boardRowSize, boardColSize, word, i, j) == true)
				return true;
		}
	}
	return false;
}
