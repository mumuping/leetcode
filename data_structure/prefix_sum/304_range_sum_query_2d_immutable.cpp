//
// Created by lp on 2022/11/22.
//
#include "vector"
#include "numeric"

class NumMatrix {
 public:
  NumMatrix(std::vector<std::vector<int>> &matrix) :
	  m_matrix(matrix) {
	const int row = m_matrix.size();
	if (row==0) return;

	const int col = m_matrix[0].size();
	m_square_sum = std::vector<std::vector<int>>(row + 1, std::vector<int>(col + 1));

	std::partial_sum(m_matrix[0].begin(), m_matrix[0].end(), m_square_sum[1].begin() + 1);

	for (int i = 1; i < row; ++i) {
	  std::partial_sum(matrix[i].begin(), matrix[i].end(), m_square_sum[i + 1].begin() + 1);
	  for (int j = 1; j < col + 1; ++j) {
		m_square_sum[i + 1][j] += m_square_sum[i][j];
	  }
	}
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
	return m_square_sum[row2 + 1][col2 + 1] + m_square_sum[row1][col1] - m_square_sum[row2 + 1][col1] -
		m_square_sum[row1][col2 + 1];
  }

 private:
  std::vector<std::vector<int>> m_matrix;
  std::vector<std::vector<int>> m_square_sum;
};