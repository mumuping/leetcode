//
// Created by lp on 2022/9/26.
//

#include "vector"

// 左闭右开写法
int lower_bound(const std::vector<int> &nums, int target) {
  int left = 0, right = nums.size(), mid;
  while (left < right) {
	mid = (left + right)/2;
	if (nums[mid] >= target)right = mid;
	else left = mid + 1;
  }
  return right;
}

int upper_bound(const std::vector<int> &nums, int target) {
  int left = 0, right = nums.size(), mid;
  while (left < right) {
	mid = (left + right)/2;
	if (nums[mid] > target)right = mid;
	else left = mid + 1;
  }
  return right;
}

std::vector<int> searchRange(std::vector<int> &nums, int target) {
  if (nums.size()==0)return {-1, -1};

  int left = lower_bound(nums, target);
  int right = upper_bound(nums, target) - 1;
  if (left==nums.size() || nums[left]!=target)
	return {-1, -1};
  return {left, right};
}

// 左闭右闭
int lower_bound_(const std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1, mid;
  while (left <= right) {
	mid = (left + right)/2;
	if (nums[mid] >= target) right = mid - 1;
	else left = mid + 1;
  }
  return left;
}

int upper_bound_(const std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1, mid;
  while (left <= right) {
	mid = (left + right)/2;
	if (nums[mid] > target)right = mid - 1;
	else left = mid + 1;
  }
  return right;
}

std::vector<int> searchRange_(std::vector<int> &nums, int target) {
  if (nums.size()==0)return {-1, -1};

  int left = lower_bound_(nums, target);
  int right = upper_bound_(nums, target);
  if (left==nums.size() || nums[left]!=target)
	return {-1, -1};
  return {left, right};
}