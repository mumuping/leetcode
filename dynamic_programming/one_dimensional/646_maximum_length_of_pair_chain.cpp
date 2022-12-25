//
// Created by lp on 2022/10/28.
//
#include "vector"
#include "algorithm"

// 贪心算法
int findLongestChain(std::vector<std::vector<int>> &pairs) {
  int num_pairs = pairs.size();
  if (num_pairs <= 1) return num_pairs;

  std::sort(pairs.begin(), pairs.end(),
			[](std::vector<int> &x, std::vector<int> &y) {
			  return x[1] < y[1];
			});

  int length = 1;
  int pre_b = pairs[0][1];
  for (int i = 1; i < num_pairs; ++i) {
	if (pre_b < pairs[i][0]) {
	  ++length;
	  pre_b = pairs[i][1];
	}

  }

  return length;
}

// dp + 二分
int findLongestChain_dp(std::vector<std::vector<int>> &pairs) {
  sort(pairs.begin(), pairs.end());
  std::vector<int> arr;
  for (auto p : pairs) {
	int x = p[0], y = p[1];
	if (arr.size()==0 || x > arr.back()) {
	  arr.emplace_back(y);
	} else {
	  int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	  arr[idx] = std::min(arr[idx], y);
	}
  }

  return arr.size();
}