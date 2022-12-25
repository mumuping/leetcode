//
// Created by lp on 2022/9/29.
//

#include "vector"

// 每次交换相邻两个
// 从左往右依次交换
void bubbling_sort(std::vector<int> &nums) {
  for (int i = nums.size() - 1; i > 0; --i) {
	for (int j = 0; j < i; ++j) {
	  if (nums[j] > nums[j + 1])std::swap(nums[j], nums[j + 1]);
	}
  }
}

// 从右往左依次交换
void bubbling_sort_(std::vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; ++i) {
	for (int j = nums.size() - 1; j > i; --j) {
	  if (nums[j] < nums[j - 1])std::swap(nums[j], nums[j - 1]);
	}
  }
}