//
// Created by lp on 2022/10/19.
//
#include "vector"

// dp
// f(i,j)=min (f(i-1,j), f(i-1,j-1), f(i, j-1) )+1
int maximalSquare(std::vector<std::vector<char>> &matrix) {
  int m = matrix.size(), n = matrix[0].size();
  std::vector<std::vector<int>> max_square(m, std::vector<int>(n, 0));

  int ans = 0;
  for (int i = 0; i < m; ++i) {
	for (int j = 0; j < n; ++j) {
	  if (i==0 || j==0) {
		max_square[i][j] = matrix[i][j] - '0';
	  } else {
		if (matrix[i][j]=='1') {
		  max_square[i][j] = std::min(std::min(max_square[i - 1][j], max_square[i][j - 1]),
									  max_square[i - 1][j - 1]) + 1;
		}
	  }
	  ans = std::max(ans, max_square[i][j]);
	}
  }

  return ans*ans;
}

// 从上面的状态转移方程可以发现，还可以进行空间压缩
int maximalSquare_compression(std::vector<std::vector<char>> &matrix) {
  int m = matrix.size(), n = matrix[0].size();
  std::vector<int> pre_row(n, 0);

  int left_upper = 0;
  int i, j;
  int ans = 0;
  for (i = 0; i < n; ++i) {
	pre_row[i] = matrix[0][i] - '0';
	ans = std::max(ans, pre_row[i]);
  }

  int tmp;
  for (i = 1; i < m; ++i) {
	for (j = 0; j < n; ++j) {
	  if (j==0) {
		left_upper = pre_row[0];
		pre_row[0] = matrix[i][j] - '0';
	  } else {
		if (matrix[i][j]=='1') {	// 如果是 1
		  tmp = pre_row[j];
		  pre_row[j] = std::min(std::min(left_upper, pre_row[j - 1]), pre_row[j]) + 1;
		  left_upper = tmp;
		} else {					// 如果是 0
		  left_upper = pre_row[j];
		  pre_row[j] = 0;
		}
	  }
	  ans = std::max(ans, pre_row[j]);
	}
  }

  return ans*ans;
}