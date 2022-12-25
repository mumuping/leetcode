//
// Created by lp on 2022/10/8.
//
#include "vector"
#include "string"

// 回溯法
void recall(std::vector<std::vector<std::string>> &result,
			std::vector<bool> &col_of_visited,
			std::vector<bool> &left_diag_of_visited,
			std::vector<bool> &right_diag_of_visited,
			std::vector<std::string> &comb,
			int row,
			int n) {
  // 如果 row==n 说明当前的这个结果找完了
  if (row==n) {
	result.push_back(comb);
	return;
  }

  // 遍历行 row 的所有位置，找到满足条件的位置
  int col = 0;
  for (; col < n; ++col) {
	// 如果 [row][col] 满足条件则进行递归，遍历下一行
	// 注意这里对于左对角线的判断是采用‘行号+列号’进行的 [row+col]
	// 而对于右对角线的判断是采用‘列号-行号’进行的，但是由于‘列号-行号’是关于 0 对称的，
	// 因此加 n - 1，使得起点为 0
	if (!col_of_visited[col] && !left_diag_of_visited[row + col] && !right_diag_of_visited[col - row + n - 1]) {
	  // 将 [row][col] 相应的位置标记为访问过
	  col_of_visited[col] = left_diag_of_visited[row + col] = right_diag_of_visited[col - row + n - 1] = true;

	  // 将当前位置设置为 Q
	  comb[row][col] = 'Q';

	  // 开始递归
	  recall(result, col_of_visited, left_diag_of_visited, right_diag_of_visited, comb, row + 1, n);

	  // 恢复原始装填
	  comb[row][col] = '.';
	  col_of_visited[col] = left_diag_of_visited[row + col] = right_diag_of_visited[col - row + n - 1] = false;
	}
  }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
  if (n==1)return {{"Q"}};

  std::vector<std::vector<std::string>> result;
  std::vector<std::string> comb(n, std::string(n, '.'));
  std::vector<bool> col_of_visited(n, false);
  std::vector<bool> left_diag_of_visited(2*n - 1, false);
  std::vector<bool> right_diag_of_visited(2*n - 1, false);

  recall(result, col_of_visited, left_diag_of_visited, right_diag_of_visited, comb, 0, n);
  return result;
}
