//
// Created by lp on 2023/3/25.
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

int dfs(const std::vector<std::pair<int, int>> &price_discount,
		std::unordered_map<std::string, std::pair<int, int>> &memory,
		int &used_money,
		int index,
		int remain_money,
		int remain_discount) {
  if (index >= price_discount.size() || remain_money <= 0) {
	used_money = 0;
	return 0;
  }
  std::string status = std::to_string(index) +
	  std::to_string(remain_money) +
	  std::to_string(remain_discount);
  if (memory.count(status)) {
	used_money = memory[status].second;
	return memory[status].first;
  }

  int buy_without_discount = 0, buy_with_discount = 0, skip = 0;
  int used_buy_without_discount = 0, used_buy_with_discount = 0, used_skip = 0;
  if (remain_money >= price_discount[index].first) {
	buy_without_discount =
		dfs(price_discount,
			memory,
			used_buy_without_discount,
			index + 1,
			remain_money - price_discount[index].first,
			remain_discount) + 1;
  }
  if (remain_discount && remain_money >= price_discount[index].second) {
	buy_with_discount =
		dfs(price_discount,
			memory,
			used_buy_with_discount,
			index + 1,
			remain_money - price_discount[index].second,
			remain_discount - 1) + 1;
  }
  skip = dfs(price_discount, memory, used_skip, index + 1, remain_money, remain_discount);
  int res;
  if (buy_with_discount > buy_without_discount) {
	res = buy_with_discount;
	used_money = used_buy_with_discount + price_discount[index].second;
  } else if (buy_with_discount==buy_without_discount) {
	res = buy_with_discount;
	used_money = std::min(used_buy_with_discount + price_discount[index].second,
						  used_buy_without_discount + price_discount[index].first);
  } else {
	res = buy_without_discount;
	used_money = used_buy_without_discount + price_discount[index].first;
  }

  if (res==skip) {
	used_money = std::min(used_money, used_skip);
  } else if (res < skip) {
	res = skip;
	used_money = used_skip;
  }

  memory[status] = std::make_pair(res, used_money);
  return res;
}

void solution() {
  int N, X, Y;
  std::cin >> N >> X >> Y;
  std::vector<std::pair<int, int>> price_discount(N);
  for (auto &it : price_discount) {
	std::cin >> it.first >> it.second;
  }

  std::unordered_map<std::string, std::pair<int, int>> memory;
  int used_money = 0, count;
  count = dfs(price_discount, memory, used_money, 0, X, Y);
  std::cout << count << " " << used_money << std::endl;
}
