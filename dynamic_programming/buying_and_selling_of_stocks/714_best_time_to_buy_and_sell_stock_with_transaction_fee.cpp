//
// Created by lp on 2022/10/30.
//
#include "vector"

// 状态转移方程
// 每天都有四种状态
// 在 i 天买入 buy
// 在 i 天卖出
// 在 i 天持有股票，不做任何操作
// 在 i 天未持有股票，不做任何操作
int maxProfit(std::vector<int> &prices, int fee) {
  int size = prices.size();
  if (size <= 1) return 0;

  std::vector<int> buy(size, 0);
  std::vector<int> sell(size, 0);
  std::vector<int> keep_with_stock(size, 0);
  std::vector<int> keep_without_stock(size, 0);
  buy[0] = keep_with_stock[0] = -prices[0] - fee;
  sell[0] = keep_without_stock[0] = 0;

  for (int i = 1; i < size; ++i) {
	sell[i] = std::max(buy[i - 1], keep_with_stock[i - 1]) + prices[i];
	buy[i] = std::max(sell[i - 1], keep_without_stock[i - 1]) - prices[i] - fee;
	keep_with_stock[i] = std::max(keep_with_stock[i - 1], buy[i - 1]);
	keep_without_stock[i] = std::max(sell[i - 1], keep_without_stock[i - 1]);
  }

  return std::max(sell[size - 1], keep_without_stock[size - 1]);
}

// 压缩空间
int maxProfit_compression(std::vector<int> &prices, int fee) {
  int size = prices.size();
  if (size <= 1) return 0;

  int buy, sell, keep_with_stock, keep_without_stock;
  buy = keep_with_stock = -prices[0] - fee;
  sell = keep_without_stock = 0;

  int tmp_buy, tmp_sell, tmp_kws, tmp_kwos;
  for (int i = 1; i < size; ++i) {
	tmp_kws = std::max(buy, keep_with_stock);
	tmp_kwos = std::max(sell, keep_without_stock);
	tmp_buy = tmp_kwos - prices[i] - fee;
	tmp_sell = tmp_kws + prices[i];
	std::swap(tmp_kwos, keep_without_stock);
	std::swap(tmp_kws, keep_with_stock);
	std::swap(tmp_sell, sell);
	std::swap(tmp_buy, buy);
  }

  return std::max(sell, keep_without_stock);
}