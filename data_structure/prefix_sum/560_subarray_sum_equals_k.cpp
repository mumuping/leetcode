//
// Created by lp on 2022/11/23.
//
#include "vector"
#include "unordered_map"

int subarraySum(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (n==0) return 0;
  if (n==1) return k==nums[0] ? 1 : 0;

  std::unordered_map<int, int> map;
  map[0] = 1;
  int prefix_sum = 0;
  int count = 0;
  for (const int i : nums) {
	prefix_sum += i;
	count += map[prefix_sum - k];
	++map[prefix_sum];
  }

  return count;
}