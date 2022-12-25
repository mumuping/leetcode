//
// Created by lp on 2022/10/17.
//
#include "vector"
#include "numeric"

int numberOfArithmeticSlices(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums < 3) return 0;

  int total = 0, number_of_current_sequence = 0;
  int begin = 0, end = 2;
  int difference = nums[1] - nums[0];
  for (; end < size_nums; ++end) {
	if (nums[end] - nums[end - 1]!=difference) {
	  difference = nums[end] - nums[end - 1];
	  begin = end - 1;
	  total += number_of_current_sequence;
	  number_of_current_sequence = 0;
	} else {
	  number_of_current_sequence += end - 1 - begin;
	}
  }
  total += number_of_current_sequence;    // 若在末尾存在等差数组，则需将其也加入其中

  return total;
}

// 另一种未压缩空间的 dp
// f(n)=f(n-1)+1 以 n 结尾的等差数组个数
int numberOfArithmeticSlices_(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums < 3) return 0;

  std::vector<int> dp(size_nums, 0);
  for (int i = 2; i < size_nums; ++i) {
	if (nums[i] - nums[i - 1]==nums[i - 1] - nums[i - 2])
	  dp[i] = dp[i - 1] + 1;
  }

  // 再把所有的 dp 累加
  return std::accumulate(dp.begin(), dp.end(), 0);
}
