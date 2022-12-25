//
// Created by lp on 2022/10/18.
//
#include "vector"

// dp
// f(i,j)=min(f(i-1,j),f(i,j-1))+grid[i,j]
int minPathSum(std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  std::vector<std::vector<int>> path_sum(m, std::vector<int>(n, 0));
  path_sum[0][0] = grid[0][0];

  for (int i = 0; i < m; ++i) {
	for (int j = 0; j < n; ++j) {
	  if (i - 1 >= 0 && j - 1 >= 0) {
		path_sum[i][j] = std::min(path_sum[i][j - 1], path_sum[i - 1][j]) + grid[i][j];
	  } else if (i - 1 >= 0) {
		path_sum[i][j] = path_sum[i - 1][j] + grid[i][j];
	  } else if (j - 1 >= 0) {
		path_sum[i][j] = path_sum[i][j - 1] + grid[i][j];
	  }
	}
  }

  return path_sum[m - 1][n - 1];
}

// 根据状态转移方程可以看出，只需要保存当前位置的上一行最小值即可，压缩空间
int minPathSum_compression(std::vector<std::vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  std::vector<int> pre_row_path_sum(n, 0);
  pre_row_path_sum[0] = grid[0][0];

  for (int i = 0; i < m; ++i) {
	for (int j = 0; j < n; ++j) {
	  if (i > 0 && j > 0) {
		pre_row_path_sum[j] = std::min(pre_row_path_sum[j], pre_row_path_sum[j - 1]) + grid[i][j];
	  } else if (i > 0) {
		pre_row_path_sum[j] = pre_row_path_sum[j] + grid[i][j];
	  } else if (j > 0) {
		pre_row_path_sum[j] = pre_row_path_sum[j - 1] + grid[i][j];
	  }
	}
  }

  return pre_row_path_sum[n - 1];
}