//
// Created by lp on 2022/11/13.
//
#include "vector"

// 每个数依次旋转
void rotate(std::vector<std::vector<int>> &matrix) {
  int n = matrix.size() - 1;
  if (n==0) return;

  int tmp;
  for (int i = 0; i <= n/2; ++i) {
	for (int j = i; j < n - i; ++j) {
	  tmp = matrix[i][j];
	  matrix[i][j] = matrix[n - j][i];
	  matrix[n - j][i] = matrix[n - i][n - j];
	  matrix[n - i][n - j] = matrix[j][n - i];
	  matrix[j][n - i] = tmp;
	}
  }
}