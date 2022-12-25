//
// Created by lp on 2022/9/29.
//

#include "vector"

// 左闭右闭
void merge_sort(std::vector<int> &nums, int l, int r) {
  if (l >= r)return;

  std::vector<int>::iterator left = nums.begin() + l;
  int mid = (l + r)/2;
  int first_of_r = mid + 1;
  merge_sort(nums, l, mid);
  merge_sort(nums, first_of_r, r);

  std::vector<int> tmp;
  tmp.reserve(r - l + 1);
  while (l <= mid || first_of_r <= r) {
	if (first_of_r > r || (l <= mid && nums[l] < nums[first_of_r])) {
	  tmp.push_back(nums[l]);
	  ++l;
	} else {
	  tmp.push_back(nums[first_of_r]);
	  ++first_of_r;
	}
  }

  std::copy(tmp.begin(), tmp.end(), left);
}

// 左闭右开
void merge_sort_(std::vector<int> &nums, int l, int r) {
  if (l + 1 >= r)return;

  int left = l, mid = (l + r)/2, right = mid;
  merge_sort(nums, l, mid);
  merge_sort(nums, mid, r);

  // 合并两个数组
  std::vector<int> tmp;
  tmp.reserve(r - l + 1);
  while (left < mid || right < r) {
	if (right >= r || (left < mid && nums[left] < nums[right])) {
	  tmp.push_back(nums[left++]);
	} else {
	  tmp.push_back(nums[right++]);
	}
  }
  std::copy(tmp.begin(), tmp.end(), nums.begin() + l);
}