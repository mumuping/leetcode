//
// Created by lp on 2022/11/7.
//
#include "vector"
#include "cmath"
#include "algorithm"

// 差的平方和 Σ(x-t)^2 最小时，t 为平均值；差的绝对值之和 Σ|x-t| 最小时，t 为中位数。
// 第一种方法：排序+中位数
int minMoves2(std::vector<int> &nums) {
  int size = nums.size();
  if (size==1) return 0;
  if (size==2) return abs(nums[0] - nums[1]);

  std::sort(nums.begin(), nums.end());

  int moves = 0, i = 0;
  while (i < size/2) {
	moves += nums[size - 1 - i] - nums[i];
	++i;
  }

  return moves;
}