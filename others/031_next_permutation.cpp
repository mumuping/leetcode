//
// Created by 18315 on 2023/2/9.
//
#include "vector"
#include "algorithm"

void nextPermutation(std::vector<int> &nums) {
  if (nums.empty() || nums.size() == 1) return;
  int n = nums.size();
  if (n == 2) {
    std::swap(nums[0], nums[1]);
    return;
  }

  int i = n - 1, before_i = n - 2;
  while (before_i >= 0 && nums[i] <= nums[before_i]) {
    --i;
    --before_i;
  }
  if (i == 0) {
    std::reverse(nums.begin(), nums.end());
    return;
  }

  int index_of_swapping = n - 1;
  while (index_of_swapping > before_i && nums[index_of_swapping] <= nums[before_i]) {
    --index_of_swapping;
  }
  std::swap(nums[index_of_swapping], nums[before_i]);
  std::reverse(nums.begin() + i, nums.end());
  return;
}