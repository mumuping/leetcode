//
// Created by lp on 2022/9/29.
//

#include "vector"

// 采用左闭右闭
void quick_sort(std::vector<int> &nums, int l, int r) {
  if (l >= r)return;

  int left = l, right = r, pivot = nums[l];
  while (left < right) {
	// 从右往左开始查找比 pivot 小的元素
	while (left < right && nums[right] >= pivot) --right;
	nums[left] = nums[right];
	// 从左往右开始查找比 pivot 大的元素
	while (left < right && nums[left] <= pivot)++left;
	nums[right] = nums[left];
  }
  // 把 pivot 放回正确的位置
  nums[left] = pivot;

  quick_sort(nums, l, left - 1);
  quick_sort(nums, left + 1, r);
}

// 采用左闭右开
void quick_sort_(std::vector<int> &nums, int l, int r) {
  if (l + 1 >= r)return;

  int left = l, right = r, pivot = nums[left];
  while (left + 1 < right) {
	// 从右往左开始寻找小于 pivot 的元素
	while (left + 1 < right && nums[right - 1] >= pivot)--right;
	nums[left] = nums[right - 1];
	// 从左往右开始寻找大于 pivot 的元素
	while (left + 1 < right && nums[left] <= pivot)++left;
	nums[right - 1] = nums[left];
  }
  // 把 pivot 放回正确的位置
  nums[left] = pivot;

  quick_sort(nums, l, left);
  quick_sort(nums, left + 1, r);
}
