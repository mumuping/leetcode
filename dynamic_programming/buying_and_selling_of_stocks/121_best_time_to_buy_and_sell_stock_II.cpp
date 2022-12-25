//
// Created by lp on 2022/10/25.
//
#include "vector"

// 遍历一遍数组，在每一个位置 i 时，记录 i 位置之前所有价格中的最低价格，
// 然后将当前的价格作为售出价格，查看当前收益是不是最大收益即可
int maxProfit(std::vector<int> &prices) {
  int size = prices.size();
  if (size <= 1) return 0;

  int lower = 0;
  while (lower + 1 < size) {
	if (prices[lower + 1] > prices[lower]) break;
	++lower;
  }

  int idx = lower + 1;
  int ans = 0;
  for (; idx < size; ++idx) {
	if (prices[idx] < prices[lower]) {
	  lower = idx;
	}
	ans = std::max(ans, prices[idx] - prices[lower]);
  }
  return ans;
}