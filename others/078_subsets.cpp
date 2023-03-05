//
// Created by lp on 2023/3/5.
//
#include "vector"

std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
  if (nums.empty()) return {{}};

  const int n = nums.size();
  const int counts = 1 << n;
  std::vector<std::vector<int>> res;
  int i = 1, j = 1, index = 0;
  for (; i < counts; ++i) {
	j = i;
	index = 0;
	std::vector<int> subset;
	while (j!=0) {
	  if (j & 1) {
		subset.emplace_back(nums[index]);
	  }
	  j >>= 1;
	  ++index;
	}
	res.push_back(std::move(subset));
  }
  res.push_back({});
  return res;
}

std::vector<std::vector<int>> subsets_(std::vector<int> &nums) {
  if (nums.empty()) return {{}};
  const int n = nums.size();
  const int count = 1 << n;
  std::vector<std::vector<int>> res;
  for (int mask = 1; mask < count; ++mask) {
	std::vector<int> subset;
	for (int i = 0; i < n; ++i) {
	  if (mask & (1 << i)) subset.push_back(nums[i]);
	}
	res.push_back(std::move(subset));
  }
  res.push_back({});
  return res;
}

void dfs(std::vector<int> &nums,
		 std::vector<std::vector<int>> &ans,
		 std::vector<int> &subset,
		 int cur) {
  if (cur==nums.size()) {
	ans.push_back(subset);
	return;
  }
  subset.push_back(nums[cur]);
  dfs(nums, ans, subset, cur + 1);
  subset.pop_back();
  dfs(nums, ans, subset, cur + 1);
}

std::vector<std::vector<int>> subsets__(std::vector<int> &nums) {
  if (nums.empty()) return {{}};
  const int n = nums.size();
  std::vector<std::vector<int>> ans;
  std::vector<int> subset;
  dfs(nums, ans, subset, 0);
  return ans;
}