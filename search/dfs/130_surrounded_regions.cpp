//
// Created by lp on 2022/10/11.
//
#include "vector"

void dfs(std::vector<std::vector<char>> &board, int i, int j, bool is_edge) {
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
  if (board[i][j]=='X' || board[i][j]==1) return;

  if (is_edge) board[i][j] = 1;      // 如果是边，把 (i,j) 标记为已访问过，这里用 1 表示
  else board[i][j] = 'X';    // 否则表示是中间的，将其改为 X

  // 递归访问周围的四个点
  dfs(board, i - 1, j, is_edge);
  dfs(board, i + 1, j, is_edge);
  dfs(board, i, j + 1, is_edge);
  dfs(board, i, j - 1, is_edge);
}

void solve(std::vector<std::vector<char>> &board) {
  // 首先利用 dfs 处理边界上的 O
  int m = board.size(), n = board[0].size();
  int i = 0, j = 0;
  // 上下边界
  for (; i < n; ++i) {
	dfs(board, 0, i, true);
	dfs(board, m - 1, i, true);
  }
  // 左右边界
  for (i = 0; i < m; ++i) {
	dfs(board, i, 0, true);
	dfs(board, i, n - 1, true);
  }

  // 开始处理内部的 O
  for (i = 1; i < m - 1; ++i) {
	for (j = 1; j < n - 1; ++j) {
	  if (board[i][j]=='O')
		dfs(board, i, j, false);
	}
  }

  // 再将 board 内部的 1 改为 O
  for (i = 0; i < m; ++i) {
	for (j = 0; j < n; ++j)
	  if (board[i][j]==1) board[i][j] = 'O';
  }

  return;
}