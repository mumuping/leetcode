//
// Created by lp on 2023/2/16.
//
#include "vector"
#include "climits"

int jump(std::vector<int> &nums) {
  if (nums.empty() || nums.size()==1) return 0;
  int n = nums.size();
  std::vector<int> steps(n, INT_MAX);
  steps[0] = 0;
  for (int i = 0; i < n; ++i) {
	for (int j = 1; j <= nums[i]; ++j) {
	  if (i + j >= n) break;
	  steps[i + j] = std::min(steps[i + j], steps[i] + 1);
	}
  }
  return steps[n - 1];
}

int jump_greedy(std::vector<int> &nums) {
  if (nums.empty() || nums.size()==1) return 0;
  int n = nums.size(), steps = 0, cur_max = 0, end = 0;
  for (int i = 0; i < n - 1; ++i) {
	cur_max = std::max(cur_max, i + nums[i]);
	if (i==end) {
	  end = cur_max;
	  ++steps;
	}
  }
  return steps;
}