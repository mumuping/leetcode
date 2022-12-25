//
// Created by lp on 2022/10/15.
//
#include "vector"
#include "cstring"

bool dfs(std::vector<std::vector<char>> &board, bool row[][9], bool col[][9], bool matrix[][3][9], int i, int j) {
  if (j==9) {
	if (++i==9) return true;
	j = 0;
  }

  while (board[i][j]!='.') {
	if (++j==9) {
	  if (++i==9) return true;
	  j = 0;
	}
  }

  for (char num = 0; num < 9; ++num) {
	if (!row[i][num] && !col[j][num] && !matrix[i/3][j/3][num]) {
	  row[i][num] = col[j][num] = matrix[i/3][j/3][num] = true;
	  board[i][j] = '1' + num;

	  if (dfs(board, row, col, matrix, i, j + 1)) return true;

	  row[i][num] = col[j][num] = matrix[i/3][j/3][num] = false;
	  board[i][j] = '.';

	}
  }

  return false;
}

void solveSudoku(std::vector<std::vector<char>> &board) {
  bool row[9][9], col[9][9], matrix[3][3][9];
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  memset(matrix, 0, sizeof(matrix));

  char tmp;
  for (char i = 0; i < 9; ++i) {
	for (char j = 0; j < 9; ++j) {
	  if (board[i][j]!='.') {
		tmp = board[i][j] - '1';
		row[i][tmp] = col[j][tmp] = matrix[i/3][j/3][tmp] = true;
	  }
	}
  }

  dfs(board, row, col, matrix, 0, 0);
}