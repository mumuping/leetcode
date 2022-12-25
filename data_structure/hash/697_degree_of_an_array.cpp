//
// Created by lp on 2022/11/25.
//
#include "unordered_map"
#include "vector"

int findShortestSubArray(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1) return n;
  if (n==2) return nums[0]==nums[1] ? 2 : 1;

  std::unordered_map<int, std::vector<int>> map;    // 频数、第一次出现位置、第二次出现位置
  for (int i = 0; i < n; ++i) {
	if (map[nums[i]].empty()) {
	  map[nums[i]].push_back(1);
	  map[nums[i]].push_back(i);
	  map[nums[i]].push_back(i);
	} else {
	  ++map[nums[i]][0];
	  map[nums[i]][2] = i;
	}
  }

  int degree = -1;
  int min_length = 0;
  for (const auto &i : map) {
	if (i.second[0] > degree) {
	  min_length = i.second[2] - i.second[1] + 1;
	  degree = i.second[0];
	}
	if (i.second[0]==degree) {
	  min_length = std::min(min_length, i.second[2] - i.second[1] + 1);
	}
  }

  return min_length;
}