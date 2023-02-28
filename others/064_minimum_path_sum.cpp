//
// Created by lp on 2023/2/28.
//
#include "vector"
#include "climits"

int minPathSum(std::vector<std::vector<int>> &grid) {
  if (grid.empty()) return -1;
  int m = grid.size();
  if (grid[0].empty()) return -1;
  int n = grid[0].size();

  std::vector<std::vector<int>> path_sum(m + 1, std::vector<int>(n + 1, INT_MAX));
  path_sum[0][1] = 0;
  for (int i = 1; i <= m; ++i) {
	for (int j = 1; j <= n; ++j) {
	  path_sum[i][j] = grid[i - 1][j - 1] + std::min(path_sum[i - 1][j], path_sum[i][j - 1]);
	}
  }
  return path_sum[m][n];
}

int minPathSum_(std::vector<std::vector<int>> &grid) {
  if (grid.empty()) return -1;
  int m = grid.size();
  if (grid[0].empty()) return -1;
  int n = grid[0].size();

  std::vector<int> path_sum(n + 1, INT_MAX);
  path_sum[1] = 0;
  for (int i = 0; i < m; ++i) {
	for (int j = 0; j < n; ++j) {
	  path_sum[j + 1] = grid[i][j] + std::min(path_sum[j], path_sum[j + 1]);
	}
  }
  return path_sum[n];
}