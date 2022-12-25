//
// Created by lp on 2022/9/25.
//

#include "vector"

int maxProfit(std::vector<int> &prices) {
  int size_prices = prices.size();
  if (size_prices==1)return 0;
  if (size_prices==2) return prices[1] - prices[0] > 0 ? prices[1] - prices[0] : 0;

  int buy_time = 0;
  int profit = 0;
  for (int i = 1; i < size_prices; ++i) {
	// 如果 prices[i] 比买入时价格高，
	// 那么就判断后面 i+1 时的价格是否比 prices[i] 高。
	// 如果 i+1 时的价格比 prices[i] 的价格高，则当前不卖出，
	// 否则当前卖出
	if (prices[i] > prices[buy_time]) {
	  // 如果到达末尾，则直接卖出
	  if (i + 1==size_prices) {
		profit += prices[i] - prices[buy_time];
	  } else {    // 否则判断后一个时间是否比当前价格更高
		if (prices[i] > prices[i + 1]) {
		  // 当前时间价格比后一个时间价格更高，则卖出
		  profit += prices[i] - prices[buy_time];
		  buy_time = i + 1;
		}
	  }
	} else {
	  buy_time = i;
	}
  }

  return profit;
}