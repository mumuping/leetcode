//
// Created by lp on 2023/2/19.
//
#include "vector"
#include "string"

void solveNQueen_aux(int n, int row, std::vector<bool> &col_visited,
					 std::vector<bool> &left_top_right_bottom_visited,
					 std::vector<bool> &left_bottom_right_top_visited,
					 std::vector<std::string> &combination,
					 std::vector<std::vector<std::string>> &combinations) {
  if (row==n) {
	combinations.push_back(combination);
	return;
  }
  for (int i = 0; i < n; ++i) {
	if (!col_visited[i] && !left_top_right_bottom_visited[n - 1 + i - row] &&
		!left_bottom_right_top_visited[i + row]) {
	  col_visited[i] = left_top_right_bottom_visited[n - 1 + i - row] = left_bottom_right_top_visited[i + row] = true;
	  combination[row][i] = 'Q';
	  solveNQueen_aux(n,
					  row + 1,
					  col_visited,
					  left_top_right_bottom_visited,
					  left_bottom_right_top_visited,
					  combination,
					  combinations);
	  combination[row][i] = '.';
	  col_visited[i] = left_top_right_bottom_visited[n - 1 + i - row] = left_bottom_right_top_visited[i + row] = false;
	}
  }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
  if (n==1) return {{"Q"}};

  std::vector<bool> col_visited(n, false),
	  left_top_right_bottom_visited(2*n - 1, false),
	  left_bottom_right_top_visited(2*n - 1, false);
  std::vector<std::string> combination(n,
									   std::string(n, '.'));
  std::vector<std::vector<std::string>> combinations;

  solveNQueen_aux(n,
				  0,
				  col_visited,
				  left_top_right_bottom_visited,
				  left_bottom_right_top_visited,
				  combination,
				  combinations);
  return combinations;
}