//
// Created by lp on 2022/11/26.
//
#include "vector"
#include "cmath"

// 若不能修改数组
// 第一种方法：二分查找
int findDuplicate_binary(std::vector<int> &nums) {
  int n = nums.size();
  int l = 1, r = n - 1, mid;
  int count = 0;
  while (l < r) {
	mid = (l + r) >> 1;
	count = 0;
	for (int i = 0; i < n; ++i) {
	  if (nums[i] <= mid) ++count;
	}

	if (count <= mid) l = mid + 1;
	else r = mid;
  }

  return l;
}

// 第二种方法：二进制
int findDuplicate_bits(std::vector<int> &nums) {
  int n = nums.size(), res = 0;
  int bit_max = 31;    // 确定二进制下的最高位
  while (!((n - 1) >> bit_max))
	--bit_max;

  int x, y;
  for (int bit = 0; bit <= bit_max; ++bit) {
	x = 0;
	y = 0;
	for (int i = 0; i < n; ++i) {
	  if (nums[i] & (1 << bit)) ++x;
	  if (i >= 1 && (i & (1 << bit))) ++y;
	}
	if (x > y) res |= (1 << bit);
  }

  return res;
}

// 第三种方法：快慢指针
int findDuplicate_(std::vector<int> &nums) {
  int slow = 0, fast = 0;
  do {
	slow = nums[slow];
	fast = nums[nums[fast]];
  } while (slow!=fast);
  slow = 0;
  while (slow!=fast) {
	slow = nums[slow];
	fast = nums[fast];
  }
  return slow;
}

// 若可以修改数组的话
int findDuplicate(std::vector<int> &nums) {
  int n = nums.size();
  int res = 0;
  for (int i = 0; i < n; ++i) {
	if (nums[std::abs(nums[i])] < 0) {
	  res = abs(nums[i]);
	  break;
	} else {
	  nums[std::abs(nums[i])] = -nums[std::abs(nums[i])];
	}
  }

  for (int i = 0; i < n; ++i) {
	nums[i] = std::abs(nums[i]);
  }

  return res;
}