//
// Created by lp on 2023/3/4.
//
#include "vector"

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty()) return false;
  int m = matrix.size();
  if (matrix[0].empty()) return false;
  int n = matrix[0].size();

  int row = 0, col = n - 1;
  int tmp;
  while (row < m && col >= 0) {
	tmp = matrix[row][col];
	if (tmp==target) return true;
	else if (tmp < target) ++row;
	else --col;
  }
  return false;
}