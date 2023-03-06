//
// Created by lp on 2023/3/6.
//
#include "vector"
#include "string"

bool exist_aux(std::vector<std::vector<char>> &board,
			   std::vector<std::vector<bool>> &is_visited,
			   const std::string &word,
			   int index,
			   int row,
			   int col) {
  if (board[row][col]!=word[index]) return false;
  if (index==word.length() - 1) return true;

  is_visited[row][col] = true;
  ++index;
  const char direction[5] = {-1, 0, 1, 0, -1};
  int next_row, next_col;
  for (int i = 0; i < 4; ++i) {
	next_row = row + direction[i];
	next_col = col + direction[i + 1];
	if (next_col >= 0 && next_col < board[0].size() &&
		next_row >= 0 && next_row < board.size() && !is_visited[next_row][next_col])
	  if (exist_aux(board, is_visited, word, index, next_row, next_col))
		return true;
  }
  is_visited[row][col] = false;
  return false;
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
  const int m = board.size(), n = board[0].size();
  const int length_word = word.length();

  std::vector<std::vector<bool>> is_visited(m, std::vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
	for (int j = 0; j < n; ++j) {
	  if (exist_aux(board, is_visited, word, 0, i, j))
		return true;
	}
  }
  return false;
}
