//
// Created by lp on 2022/11/25.
//
#include "vector"
#include "unordered_map"

bool containsDuplicate(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1) return false;
  if (n==2) return nums[0]==nums[1];

  std::unordered_map<int, int> map;
  for (int i = 0; i < n; ++i) {
	if (map[nums[i]]==1) return true;
	else map[nums[i]] = 1;
  }

  return false;
}