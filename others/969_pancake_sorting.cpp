//
// Created by 18315 on 2023/1/19.
//
#include "vector"
#include "algorithm"

// 暴力
std::vector<int> pancakeSort(std::vector<int> &arr) {
  const int n = arr.size();
  if (n <= 1) return {};

  std::vector<int> res;
  res.reserve(n);
  int max_index = 0;
  for (int i = 0; i < n; ++i) {
    max_index = 0;
    for (int j = 1; j < n - i; ++j) {
      if (arr[max_index] < arr[j]) max_index = j;
    }
    if (max_index == n - i - 1) continue;
    res.emplace_back(max_index + 1);
    std::reverse(arr.begin(), arr.begin() + max_index + 1);
    res.emplace_back(n - i);
    std::reverse(arr.begin(), arr.begin() + n - i);
  }

  return res;
}

// 寻找最小的翻转次数和方案是 NP 问题