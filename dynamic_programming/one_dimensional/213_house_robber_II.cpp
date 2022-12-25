//
// Created by lp on 2022/10/27.
//
#include "vector"

// dp
// 可以分成两部分，把第一个和最后一个隔开分别计算
// 然后取二者之间的最大值
int rob(std::vector<int> &nums) {
  int size = nums.size();
  if (size==0) return 0;
  if (size==1) return nums[0];

  std::vector<int> dp(size + 1, 0);
  dp[1] = nums[0];
  for (int i = 2; i <= size - 1; ++i) {
	dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }

  int max_money = dp[size - 1];
  dp.clear();
  dp[0] = dp[1] = 0;
  dp[2] = nums[1];
  for (int i = 3; i <= size; ++i) {
	dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }

  return std::max(dp[size], max_money);
}

// 将上面的方法压缩空间
int rob_compression(std::vector<int> &nums) {
  int size = nums.size();
  if (size==0) return 0;
  if (size==1) return nums[0];

  int pre_pre = 0, pre = nums[0];
  int max_money, tmp;
  for (int i = 1; i < size - 1; ++i) {
	tmp = pre;
	pre = std::max(pre, pre_pre + nums[i]);
	pre_pre = tmp;
  }
  max_money = pre;

  pre_pre = 0;
  pre = nums[1];
  for (int i = 2; i < size; ++i) {
	tmp = pre;
	pre = std::max(pre, pre_pre + nums[i]);
	pre_pre = tmp;
  }

  return std::max(pre, max_money);
}

