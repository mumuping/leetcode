//
// Created by lp on 2023/2/10.
//
#include "vector"

int searchInsert(std::vector<int> &nums, int target) {
  if (nums.empty()) return 0;

  int left = 0, right = nums.size(), mid;
  while (left < right) {
	mid = left + (right - left)/2;
	if (nums[mid]==target) return mid;
	else if (nums[mid] < target) left = mid + 1;
	else right = mid;
  }
  return left;
}