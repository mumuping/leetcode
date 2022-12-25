//
// Created by lp on 2022/10/26.
//
#include "vector"
#include "climits"

// dp
// 状态机+状态转移方程
int maxProfit(std::vector<int> &prices) {
  int size_prices = prices.size();
  if (size_prices <= 1) return 0;

  std::vector<std::vector<int>> dp(size_prices + 1, std::vector<int>(3, 0));
  dp[0][0] = dp[0][1] = 0;
  dp[0][2] = INT_MIN;

  for (int i = 1; i <= size_prices; ++i) {
	dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
	dp[i][1] = dp[i - 1][2] + prices[i - 1];
	dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][0] - prices[i - 1]);
  }

  return std::max(std::max(dp[size_prices][0], dp[size_prices][1]), dp[size_prices][2]);
}

// 压缩空间
int maxProfit_compression(std::vector<int> &prices) {
  int size_prices = prices.size();
  if (size_prices <= 1) return 0;

  int dp[3] = {0, 0, INT_MIN};

  int zero, one, two;
  for (int i = 1; i <= size_prices; ++i) {
	zero = std::max(dp[0], dp[1]);
	one = dp[2] + prices[i - 1];
	two = std::max(dp[2], dp[0] - prices[i - 1]);
	dp[0] = zero;
	dp[1] = one;
	dp[2] = two;
  }

  return std::max(std::max(one, two), zero);
}