//
// Created by lp on 2023/2/19.
//
#include "vector"
#include "climits"

int maxSubArray(std::vector<int> &nums) {
  if (nums.empty()) return 0;
  int n = nums.size();
  if (n==1) return nums[0];

  int max_value = INT_MIN, sub_value = 0;
  for (int i = 0; i < n; ++i) {
	sub_value += nums[i];
	max_value = std::max(max_value, sub_value);
	if (sub_value < 0) sub_value = 0;
  }

  return max_value;
}

int maxSubArray_divide_aux(std::vector<int> &nums, int left, int right) {
  if (left >= right) return 0;
  if (left + 1==right) return nums[left];

  int mid = left + (right - left)/2;
  int left_value = maxSubArray_divide_aux(nums, left, mid),
	  right_value = maxSubArray_divide_aux(nums, mid + 1, right),
	  mid_value = nums[mid];
  int mid_left = 0, mid_right = 0, tmp = 0;
  for (int i = mid - 1; i >= left; --i) {
	mid_left += nums[i];
	tmp = std::max(tmp, mid_left);
  }
  mid_left = tmp;
  tmp = 0;
  for (int i = mid + 1; i < right; ++i) {
	mid_right += nums[i];
	tmp = std::max(tmp, mid_right);
  }
  mid_right = tmp;
  mid_value += mid_left + mid_right;
  return std::max(left_value, std::max(mid_value, right_value));
}

int maxSubArray_divide(std::vector<int> &nums) {
  if (nums.empty()) return 0;
  int n = nums.size();
  if (n==1) return nums[0];
  return maxSubArray_divide_aux(nums, 0, n);
}