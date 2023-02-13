//
// Created by 18315 on 2023/2/13.
//
#include "vector"
#include "algorithm"

// 置换
int firstMissingPositive(std::vector<int> &nums) {
  if (nums.empty()) return 1;
  int n = nums.size();
  if (n == 1) return nums[0] == 1 ? 2 : 1;

  int tmp, i;
  for (i = 0; i < n; ++i) {
    while (nums[i] > 0 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] == nums[i]) {
      tmp = nums[nums[i] - 1];
      nums[nums[i] - 1] = nums[i];
      nums[i] = tmp;
    }
  }

  i = 0;
  while (i < n && nums[i] == i + 1) ++i;

  return i + 1;
}

// 打标签
int firstMissingPositive_(std::vector<int> &nums) {
  if (nums.empty()) return 1;
  int n = nums.size();
  if (n == 1) return nums[0] == 1 ? 2 : 1;

  for (int &num : nums) {
    if (num <= 0) num = n + 1;
  }

  int tmp;
  for (int i = 0; i < n; ++i) {
    tmp = std::abs(nums[i]);
    if (tmp <= n) nums[tmp - 1] = -std::abs(nums[tmp - 1]);
  }
  for (int i = 0; i < n; ++i) {
    if (nums[i] > 0) return i + 1;
  }
  return n + 1;
}