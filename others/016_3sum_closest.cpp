//
// Created by lp on 2023/2/6.
//
#include "vector"
#include "algorithm"
#include "climits"

int threeSumClosest(std::vector<int> &nums, int target) {
  int n = nums.size(), sum3 = 0, distance = INT_MAX;
  if (n < 3) return 0;
  if (n==3) return nums[0] + nums[1] + nums[2];

  std::sort(nums.begin(), nums.end());
  for (int first = 0; first < n - 2; ++first) {
	if (first > 0 && nums[first]==nums[first - 1]) continue;
	int second = first + 1, third = n - 1, tmp = 0;
	while (second < third) {
	  tmp = nums[first] + nums[second] + nums[third];
	  if (tmp==target) return tmp;
	  if (std::abs(tmp - target) < distance) {
		sum3 = tmp;
		distance = std::abs(tmp - target);
	  }

	  if (tmp < target) {
		++second;
		while (second < third && nums[second]==nums[second - 1]) ++second;
	  } else {
		--third;
		while (second < third && nums[third]==nums[third + 1]) --third;
	  }
	}
  }

  return sum3;
}