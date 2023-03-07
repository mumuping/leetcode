//
// Created by lp on 2023/3/7.
//
#include "vector"

bool search(std::vector<int> &nums, int target) {
  if (nums.empty()) return false;
  int left = 0, right = nums.size() - 1, mid;
  if (right==0) return target==nums[0];

  while (left <= right) {
	mid = left + (right - left)/2;
	if (nums[mid]==target) return true;

	if (nums[mid]==nums[left] && nums[mid]==nums[right]) {
	  ++left;
	  --right;
	} else if (nums[mid] >= nums[left]) {
	  if (target >= nums[left] && target <= nums[mid]) right = mid - 1;
	  else left = mid + 1;
	} else {
	  if (target >= nums[mid] && target <= nums[right]) left = mid + 1;
	  else right = mid - 1;
	}
  }
  return false;
}
