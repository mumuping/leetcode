//
// Created by lp on 2023/3/4.
//

#include "vector"
#include "algorithm"

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty()) return false;
  int m = matrix.size();
  if (matrix[0].empty()) return false;
  int n = matrix[0].size();

  int top = 0, down = m, mid;
  while (top < down) {
	mid = top + (down - top)/2;
	if (matrix[mid][0]==target) return true;
	else if (matrix[mid][0] < target) top = mid + 1;
	else down = mid;
  }
  if (top==0) return false;

  --top;
  auto iter = std::lower_bound(matrix[top].begin(),
							   matrix[top].end(),
							   target);
  if (iter==matrix[top].end() || *iter!=target) return false;
  else return true;
}

bool searchMatrix_(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty()) return false;
  int m = matrix.size();
  if (matrix[0].empty()) return false;
  int n = matrix[0].size();

  auto row = std::upper_bound(matrix.begin(),
							  matrix.end(),
							  target,
							  [](const int val, const std::vector<int> &a) {
								return val < a[0];
							  });
  if (row==matrix.begin()) return false;
  --row;
  return std::binary_search(row->begin(), row->end(), target);
}

bool searchMatrix__(std::vector<std::vector<int>> &matrix, int target) {
  if (matrix.empty()) return false;
  int m = matrix.size();
  if (matrix[0].empty()) return false;
  int n = matrix[0].size();

  int left = 0, right = m*n - 1, mid, tmp;
  while (left <= right) {
	mid = left + (right - left)/2;
	tmp = matrix[mid/n][mid%n];
	if (tmp==target) return true;
	else if (tmp < target) left = mid + 1;
	else right = mid - 1;
  }
  return false;
}