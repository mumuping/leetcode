//
// Created by lp on 2023/2/22.
//
#include "vector"

std::vector<std::vector<int>> generateMatrix(int n) {
  if (n <= 0) return {{}};
  if (n==1) return {{1}};

  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
  int top = 0, bottom = n - 1, left = 0, right = n - 1;
  int value = 1;
  while (true) {
	for (int i = left; i <= right; ++i) matrix[top][i] = value++;
	if (++top > bottom) break;
	for (int i = top; i <= bottom; ++i) matrix[i][right] = value++;
	if (--right < left) break;
	for (int i = right; i >= left; --i) matrix[bottom][i] = value++;
	if (--bottom < top) break;
	for (int i = bottom; i >= top; --i) matrix[i][left] = value++;
	if (++left > right) break;
  }
  return matrix;
}