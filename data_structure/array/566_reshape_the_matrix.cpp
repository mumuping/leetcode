//
// Created by lp on 2022/11/24.
//
#include "vector"

std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &mat, int r, int c) {
  const int m = mat.size();
  if (m==0) return {};
  const int n = mat[0].size();
  if (m*n!=r*c) return mat;

  std::vector<std::vector<int>> new_mat(r, std::vector<int>(c));
  int mat_row = 0, mat_col = 0;
  for (int i = 0; i < r; ++i) {
	for (int j = 0; j < c; ++j) {
	  new_mat[i][j] = mat[mat_row][mat_col];
	  ++mat_col;
	  if (mat_col==n) {
		++mat_row;
		mat_col = 0;
	  }
	}
  }

  return new_mat;
}