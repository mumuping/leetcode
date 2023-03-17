//
// Created by 18315 on 2023/3/16.
//
#include <iostream>
#include <vector>

bool dfs(const std::vector<int> &candies,
         std::vector<int> &res,
         int cur_index,
         int sum,
         int target) {
  if (sum == target) {
    return true;
  } else if (sum > target) {
    return false;
  } else {
    if (cur_index >= candies.size()) return false;
    sum += candies[cur_index];
    res.emplace_back(cur_index);
    if (dfs(candies, res, cur_index + 1, sum, target)) return true;
    sum -= candies[cur_index];
    res.pop_back();
    if (dfs(candies, res, cur_index + 1, sum, target)) return true;
    else return false;
  };
}

void solution() {
  int nums_candy_bags = 0;
  std::cin >> nums_candy_bags;
  std::vector<int> candies(nums_candy_bags);
  int total_candies = 0;
  for (auto &it : candies) {
    std::cin >> it;
    total_candies += it;
  }

  if (nums_candy_bags == 1 || total_candies % 2 != 0) {
    std::cout << -1 << std::endl;
    return;
  }

  std::vector<int> res;
  if (dfs(candies, res, 0, 0, total_candies / 2)) {
    std::cout << total_candies / 2 << std::endl;
    for (const auto &it : res) {
      std::cout << candies[it] << " ";
    }
    std::cout << std::endl;
    for (int i = 0, j = 0; i < nums_candy_bags; ++i) {
      if (i == res[j]) {
        ++j;
      } else {
        std::cout << candies[i] << " ";
      }
    }
    std::cout << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }
}