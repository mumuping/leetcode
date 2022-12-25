//
// Created by lp on 2022/10/29.
//
#include "vector"

// 贪心
// 每次遇到如 [1,2,3,4,3,...] 将选择 4
// 遇到如 [5,4,3,8,...] 将选择 3
// 尽量给后面的元素留空间
int wiggleMaxLength(std::vector<int> &nums) {
  int size = nums.size();
  if (size==1) return 1;
  if (size==2) {
	if (nums[0]==nums[1]) return 1;
	else return 2;
  }

  int i = 1;
  while (nums[i]==nums[i - 1]) {    // 处理前导相同的元素
	++i;
	if (i==size) {
	  return 1;
	}
  }

  bool is_positive = nums[i] - nums[i - 1] > 0 ? true : false;
  int max_length = 2;
  for (i = i + 1; i < size; ++i) {
	if (is_positive) {
	  if (nums[i] - nums[i - 1] < 0) {
		++max_length;
		is_positive = !is_positive;
	  }
	} else {
	  if (nums[i] - nums[i - 1] > 0) {
		++max_length;
		is_positive = !is_positive;
	  }
	}
  }

  return max_length;
}

// dp
int wiggleMaxLength_compression(std::vector<int> &nums) {
  int size = nums.size();
  if (size==1) return 1;
  if (size==2) {
	if (nums[0]==nums[1]) return 1;
	else return 2;
  }

  std::vector<int> dp;
  dp.emplace_back(nums[0]);
  int index = 1;
  while (nums[index]==nums[index - 1]) {
	++index;
	if (index==size) return 1;
  }

  bool is_positive = nums[index] - nums[index - 1] > 0 ? true : false;
  dp.emplace_back(nums[index]);
  for (index = index + 1; index < size; ++index) {
	if (is_positive) {
	  if (nums[index] - nums[index - 1] < 0) {
		is_positive = !is_positive;
		dp.emplace_back(nums[index]);
	  } else {
		dp.back() = nums[index];	// 替换
	  }
	} else {
	  if (nums[index] - nums[index - 1] > 0) {
		is_positive = !is_positive;
		dp.emplace_back(nums[index]);
	  } else {
		dp.back() = nums[index];
	  }
	}
  }

  return dp.size();
}