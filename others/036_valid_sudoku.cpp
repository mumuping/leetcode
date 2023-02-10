//
// Created by lp on 2023/2/10.
//
#include "vector"
#include "string.h"

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  bool rows[9][9], cols[9][9], squares[3][3][9];
  for (int i = 0; i < 9; ++i) {
	memset(rows[i], 0, sizeof(rows[i]));
	memset(cols[i], 0, sizeof(cols[i]));
  }
  for (int i = 0; i < 3; ++i) {
	for (int j = 0; j < 3; ++j) {
	  memset(squares[i][j], 0, sizeof(squares[i][j]));
	}
  }

  int c;
  for (int i = 0; i < 9; ++i) {
	for (int j = 0; j < 9; ++j) {
	  c = board[i][j] - '1';
	  if (c < 0 || c > 8) continue;
	  if (rows[i][c] || cols[j][c] || squares[i/3][j/3][c])
		return false;
	  rows[i][c] = cols[j][c] = squares[i/3][j/3][c] = true;
	}
  }
  return true;
}