//
// Created by lp on 2023/2/19.
//
#include "vector"

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
  if (matrix.empty()) return {};
  int m = matrix.size(), n = matrix[0].size();
  if (m==1) return matrix[0];

  int top = 0, bottom = m - 1, left = 0, right = n - 1;
  std::vector<int> ans;
  while (true) {
	for (int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
	if (++top > bottom) break;
	for (int i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
	if (--right < left) break;
	for (int i = right; i >= left; --i) ans.push_back(matrix[bottom][i]);
	if (--bottom < top) break;
	for (int i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
	if (++left > right) break;
  }
  return ans;
}