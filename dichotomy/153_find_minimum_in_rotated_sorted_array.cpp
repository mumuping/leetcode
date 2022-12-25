//
// Created by lp on 2022/9/27.
//

#include "vector"

// 左闭右闭
int findMin(std::vector<int> &nums) {
  int left = 0, right = nums.size() - 1, mid;
  if (right==0)return nums[0];
  if (nums[right] > nums[left])return nums[left];

  while (left + 1 < right) {
	mid = (left + right)/2;
	if (nums[mid] > nums[left])left = mid;
	else right = mid;
  }
  return nums[right];
}

// 左闭右开，其实和左闭右闭一样
int findMin_(std::vector<int> &nums) {
  int left = 0, right = nums.size(), mid;
  if (right==1 || nums[left] < nums[right - 1])return nums[0];

  while (left + 1 < right) {
	mid = (left + right)/2;
	if (nums[mid] > nums[left])left = mid;
	else right = mid;
  }
  return nums[right];
}