//
// Created by lp on 2022/10/6.
//
#include "vector"
#include "string"

// 回溯查找单词
// 该函数要求 i j 必须是合法的
bool recall(const std::vector<std::vector<char>> &board,
			const std::string &word,
			bool **is_visited,
			int position,
			int i,
			int j) {
  // 如果当前 board[i][j]==word[position]
  // 则继续向下递归
  if (board[i][j]==word[position]) {
	if (position==word.size() - 1) return true;

	// 设置 i j 已经访问过了
	is_visited[i][j] = true;
	int i_next, j_next;
	const int directions[] = {-1, 0, 1, 0, -1};
	for (char k = 0; k < 4; ++k) {
	  i_next = i + directions[k];
	  j_next = j + directions[k + 1];
	  // 保证 i_next j_next 合法，且未访问
	  if (i_next >= 0 && i_next < board.size() &&
		  j_next >= 0 && j_next < board[0].size() &&
		  !is_visited[i_next][j_next]) {
		if (recall(board, word, is_visited, position + 1, i_next, j_next))
		  return true;
	  }
	}
	// 回溯，设置 i j 未访问
	is_visited[i][j] = false;
  }
  return false;
}

bool exist(std::vector<std::vector<char>> &board, std::string word) {
  int row = board.size(), col = board[0].size();
  bool **is_visited = new bool *[row];
  for (int i = 0; i < row; ++i)
	is_visited[i] = new bool[col]();

  bool result = false;
  for (int i = 0; i < row; ++i) {
	for (int j = 0; j < col; ++j) {
	  result = recall(board, word, is_visited, 0, i, j);
	  if (result) return true;
	}
  }

  for (int i = 0; i < row; ++i)
	delete[] is_visited[i];
  delete[] is_visited;

  return false;
}
