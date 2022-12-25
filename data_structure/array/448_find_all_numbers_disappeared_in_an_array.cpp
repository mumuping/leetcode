//
// Created by lp on 2022/11/13.
//
#include "vector"
#include "cmath"

std::vector<int> findDisappearedNumbers(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> disappeared(n, 0);
  int i = 0, j = n - 1;
  for (i = 0; i < n; ++i) {
	disappeared[i] = i + 1;
  }

  // 标记哪些应该被删除
  for (i = 0; i < n; ++i) {
	disappeared[nums[i] - 1] = 0;
  }

  // 把要被删除的数放到 vector 末尾，最后一起删除，提高效率
  i = 0;
  while (i < j) {
	while (i < j && disappeared[i]!=0) ++i;
	while (i < j && disappeared[j]==0) --j;
	if (i < j) {
	  std::swap(disappeared[i], disappeared[j]);
	}
  }
  disappeared.erase(disappeared.begin() + j, disappeared.end());

  return disappeared;
}

// 利用数组这种数据结构建立 n 个桶，把所有重复出现的位置进行标记，然后再遍历一遍数组，
// 即可找到没有出现过的数字。进一步地，我们可以直接对原数组进行标记：把重复出现的数字在
// 原数组出现的位置设为负数，最后仍然为正数的位置即为没有出现过的数
std::vector<int> findDisappearedNumbers_negative(std::vector<int> &nums) {
  int n = nums.size();
  // 遍历 nums，把出现了 [1,n] 的数字的位置设置为负数
  int pos = 0;
  for (const int &num : nums) {
	pos = abs(num) - 1;
	if (nums[pos] > 0) {
	  nums[pos] = -nums[pos];
	}
  }

  // 再遍历一遍，如果该位置是负数，说明是存在该数的
  std::vector<int> disappeared;
  for (int i = 0; i < n; i++) {
	if (nums[i] > 0) {
	  disappeared.emplace_back(i + 1);
	}
  }

  return disappeared;
}