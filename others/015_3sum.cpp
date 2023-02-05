//
// Created by lp on 2023/2/5.
//
#include "vector"
#include "algorithm"

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  int n = nums.size();
  if (n < 3) return {};

  std::vector<std::vector<int>> res;
  std::sort(nums.begin(), nums.end());
  if (nums[0] > 0) return {};

  for (int first = 0; first < n - 2; ++first) {
	if (first > 0 && nums[first]==nums[first - 1]) continue;

	int third = n - 1, target = -nums[first];
	for (int second = first + 1; second < n - 1; ++second) {
	  if (second > first + 1 && nums[second]==nums[second - 1]) continue;
	  while (second < third && nums[second] + nums[third] > target) --third;
	  if (second==third) break;
	  if (nums[second] + nums[third]==target)
		res.push_back(std::vector<int>({nums[first], nums[second], nums[third]}));
	}
  }
  return res;
}

std::vector<std::vector<int>> threeSum_(std::vector<int> &nums) {
  int n = nums.size();
  if (n < 3) return {};

  std::vector<std::vector<int>> res;
  std::sort(nums.begin(), nums.end());
  if (nums[0] > 0) return {};

  for (int first = 0; first < n - 2; ++first) {
	if (first > 0 && nums[first]==nums[first - 1]) continue;
	int second = first + 1, third = n - 1, target = -nums[first];

	while (second < third) {
	  if (nums[second] + nums[third] > target || (third < n - 1 && nums[third]==nums[third + 1])) --third;
	  else if (nums[second] + nums[third] < target || (second > first + 1 && nums[second]==nums[second - 1])) ++second;
	  else {
		res.push_back({nums[first], nums[second], nums[third]});
		++second;
	  }
	}
  }
  return res;
}