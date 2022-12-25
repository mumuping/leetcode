//
// Created by lp on 2022/10/25.
//
#include "vector"
#include "climits"

// dp
int maxProfit(int k, std::vector<int> &prices) {
  int size_prices = prices.size();
  if (size_prices <= 1 || k <= 0) return 0;

  // size_prices/2 表示最多可以进行多少笔交易
  if (size_prices/2 < k) {    // 若 k 大于允许的最多交易，则直接计算
	int maximum = 0;
	for (int i = 1; i < size_prices; ++i) {
	  if (prices[i - 1] < prices[i])
		maximum += prices[i] - prices[i - 1];
	}
	return maximum;
  }

  // buy[i][j] 表示在第 i 天第 j 次买入时的最大收益，
  // sell[i][j] 表示在第 i 天第 j 次卖出时的最大收益
  std::vector<std::vector<int>> buy(size_prices + 1, std::vector<int>(k + 1, INT_MIN));
  std::vector<std::vector<int>> sell(size_prices + 1, std::vector<int>(k + 1, 0));
  for (int i = 1; i <= size_prices; ++i) {
	for (int j = 1; j <= k; ++j) {
	  buy[i][j] = std::max(buy[i - 1][j], sell[i - 1][j - 1] - prices[i - 1]);
	  sell[i][j] = std::max(sell[i - 1][j], buy[i - 1][j] + prices[i - 1]);
	}
  }

  return sell[size_prices][k];
}

// 从上面的状态转移方程可以看出可以进行压缩空间
int maxProfit_compression(int k, std::vector<int> &prices) {
  int size_prices = prices.size();
  if (size_prices <= 1 || k <= 0) return 0;

  // size_prices/2 表示最多可以进行多少笔交易
  if (size_prices/2 < k) {    // 若 k 大于允许的最多交易，则直接计算
	int maximum = 0;
	for (int i = 1; i < size_prices; ++i) {
	  if (prices[i - 1] < prices[i])
		maximum += prices[i] - prices[i - 1];
	}
	return maximum;
  }

  // dp
  // buy[j] 表示在第 j 次买入时的最大收益，
  // sell[j] 表示在第 j 次卖出时的最大收益
  std::vector<int> buy(k + 1, INT_MIN);
  std::vector<int> sell(k + 1, 0);
  for (int i = 0; i < size_prices; ++i) {
	for (int j = 1; j <= k; ++j) {
	  buy[j] = std::max(buy[j], sell[j - 1] - prices[i]);
	  sell[j] = std::max(sell[j], buy[j] + prices[i]);
	}
  }

  return sell[k];
}