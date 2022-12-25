//
// Created by lp on 2022/11/14.
//
#include "vector"
#include "algorithm"

// 从右上角往左下角遍历 Z 之形查找
bool searchMatrix_Z(std::vector<std::vector<int>> &matrix, int target) {
  int m = matrix.size(), n = matrix[0].size() - 1;
  int i = 0;
  while (i < m && n >= 0) {
	if (target==matrix[i][n]) return true;
	else if (target < matrix[i][n]) --n;
	else ++i;
  }

  return false;
}

// 对每一行进行二分查找
bool searchMatrix_binarySearch(std::vector<std::vector<int>> &matrix, int target) {
  int m = matrix.size(), n = matrix[0].size();
  for (int i = 0; i < m; ++i) {
	auto iter = std::lower_bound(matrix[i].begin(), matrix[i].end(), target);
	if (iter!=matrix[i].end() && *iter==target)return true;
  }

  return false;
}

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int m = matrix.size();
  if (m==0) return false;

  int n = matrix[0].size();
  if (m==1) {
	return std::binary_search(matrix[0].begin(), matrix[0].end(), target);
  }

  const auto iter = std::lower_bound(matrix[0].begin(), matrix[0].end(), target);
  if (iter!=matrix[0].end() && *iter==target) return true;
  else n = iter - matrix[0].begin() - 1;

  int i = 0;
  while (n >= 0 && i < m) {
	if (matrix[i][n]==target) return true;
	else if (matrix[i][n] < target) ++i;
	else --n;
  }

  return false;
}