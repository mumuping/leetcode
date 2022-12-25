//
// Created by lp on 2022/9/25.
//

#include "vector"
#include "algorithm"

bool checkPossibility(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums==1 || size_nums==2)return true;

  bool modified = false;
  int pre_pre = nums[0], pre = nums[1];
  int cur = 2;

  // 保证最开始 pre_pre 和 pre 是升序的
  if (pre_pre > pre) {
	modified = true;
	pre_pre = pre;
  }
  while (cur < size_nums) {
	if (nums[cur] < pre_pre) {
	  if (!modified) {
		pre_pre = pre;
		modified = true;
	  } else return false;
	} else if (pre_pre <= nums[cur] && nums[cur] < pre) {
	  if (!modified) {
		pre = nums[cur];
		pre_pre = pre;
		modified = true;
	  } else return false;
	} else {
	  pre_pre = pre;
	  pre = nums[cur];
	}
	++cur;
  }
  return true;
}

// 方法二，对两种情况直接修改，然后判断是否升序
bool checkPossibility_(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums==1 || size_nums==2)return true;

  int value_of_i = 0, value_of_i_1 = 0;
  for (int i = 0; i < size_nums - 1; ++i) {
	// 如果后一个比前一个小，则有两种情况
	value_of_i = nums[i];
	value_of_i_1 = nums[i + 1];
	if (value_of_i_1 < value_of_i) {
	  // 第一种情况：将 nums[i] 改为 nums[i+1]
	  nums[i] = value_of_i_1;
	  // 然后判断更改后序列是否是升序的
	  if (std::is_sorted(nums.begin(), nums.end())) return true;

	  // 第二种情况：将 nums[i+1] 改为 nums[i]
	  nums[i] = value_of_i;    // 先将值改回来
	  nums[i + 1] = value_of_i;
	  return std::is_sorted(nums.begin(), nums.end());
	}
  }
  return true;
}