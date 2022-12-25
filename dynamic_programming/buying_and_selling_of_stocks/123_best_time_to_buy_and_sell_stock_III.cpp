//
// Created by lp on 2022/10/26.
//
#include "vector"
#include "climits"

// 一共有五种状态
// 0. 没有交易
// 1. 第一次买
// 2. 第一次卖
// 3. 第二次买
// 4. 第二次卖
// 因此我们可以考虑每一天的这几种情况
int maxProfit(std::vector<int> &prices) {
  int size_prices = prices.size();
  if (size_prices <= 1) return 0;

  int buy1 = INT_MIN, buy2 = INT_MIN, sell1 = 0, sell2 = 0;
  for (int i = 0; i < size_prices; ++i) {
	buy1 = std::max(buy1, -prices[i]);
	sell1 = std::max(sell1, buy1 + prices[i]);
	buy2 = std::max(buy2, sell1 - prices[i]);
	sell2 = std::max(sell2, buy2 + prices[i]);
  }

  return sell2;
}