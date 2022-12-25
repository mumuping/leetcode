//
// Created by lp on 2022/10/22.
//
#include "vector"
#include "string"

// 多维的 dp
// 注意多维 dp 的除第一层循环外要从 0 开始，因为对于多维的 dp，存在 dp[i][0][1] 和 dp[i][1][0] 的情况
// 不能简单地认为这两种情况不存在，而从 dp[i][1][1] 开始
int findMaxForm(std::vector<std::string> &strs, int m, int n) {
  using std::vector;
  int num_of_strs = strs.size();
  vector<vector<vector<int>>> dp(num_of_strs + 1,
								 vector<vector<int>>(m + 1,
													 vector<int>(n + 1, 0)));

  vector<std::pair<int, int>> zeroes_ones(num_of_strs, std::pair<int, int>(0, 0));
  for (int i = 0; i < num_of_strs; ++i) {
	for (int j = 0; j < strs[i].size(); ++j) {
	  if (strs[i][j]=='0')
		++zeroes_ones[i].first;
	  else ++zeroes_ones[i].second;
	}
  }

  for (int i = 1; i <= num_of_strs; ++i) {
	// 注意这里要从 0 开始，因为对于多维的 dp，存在 dp[i][0][1] 和 dp[i][1][0] 的情况
	// 不能简单地认为这两种情况不存在，而从 dp[i][1][1] 开始
	for (int j = 0; j <= m; ++j) {
	  for (int k = 0; k <= n; ++k) {
		if (j >= zeroes_ones[i - 1].first &&
			k >= zeroes_ones[i - 1].second) {
		  dp[i][j][k] =
			  std::max(dp[i - 1][j][k], dp[i - 1][j - zeroes_ones[i - 1].first][k - zeroes_ones[i - 1].second] + 1);
		} else {
		  dp[i][j][k] = dp[i - 1][j][k];
		}
	  }
	}
  }

  return dp[num_of_strs][m][n];
}

// 显然从状态转移方程上可以看出能够进行空间压缩
int findMaxForm_compression(std::vector<std::string> &strs, int m, int n) {
  using std::vector;
  int num_of_strs = strs.size();
  vector<vector<int>> dp(vector<vector<int>>(m + 1,
											 vector<int>(n + 1, 0)));

  vector<std::pair<int, int>> zeroes_ones(num_of_strs, std::pair<int, int>(0, 0));
  for (int i = 0; i < num_of_strs; ++i) {
	for (int j = 0; j < strs[i].size(); ++j) {
	  if (strs[i][j]=='0')
		++zeroes_ones[i].first;
	  else ++zeroes_ones[i].second;
	}
  }

  for (int i = 1; i <= num_of_strs; ++i) {
	for (int j = m; j >= 0; --j) {
	  for (int k = n; k >= 0; --k) {
		if (j >= zeroes_ones[i - 1].first && k >= zeroes_ones[i - 1].second)
		  dp[j][k] = std::max(dp[j][k], dp[j - zeroes_ones[i - 1].first][k - zeroes_ones[i - 1].second] + 1);
	  }
	}
  }

  return dp[m][n];
}