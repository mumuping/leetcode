//
// Created by lp on 2022/10/22.
//
#include "vector"

// 在完全背包问题中，一个物品可以拿多次
// dp[i][j] = max(dp[i-1][j], dp[i][j-w] + v)
int knapsack(std::vector<int> &weights, std::vector<int> &values, int N, int W) {
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));
  for (int i = 1; i <= N; ++i) {
	for (int j = 1; j <= W; ++j) {
	  if (j >= weights[i - 1]) {
		dp[i][j] = std::max(dp[i][j - weights[i - 1]] + values[i - 1], dp[i - 1][j]);
	  } else {
		dp[i][j] = dp[i - 1][j];
	  }
	}
  }
  return dp[N][W];
}

// 显然上面也是可以压缩空间的
int knapsack_compression(std::vector<int> &weights, std::vector<int> &values, int N, int W) {
  std::vector<int> dp(W + 1, 0);
  for (int i = 1; i <= N; ++i) {
	for (int j = weights[i - 1]; j <= W; ++j) {	// 这里需要正向遍历
	  dp[j] = std::max(dp[j - weights[i - 1]] + values[i - 1], dp[j]);
	}
  }
  return dp[W];
}