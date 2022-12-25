//
// Created by lp on 2022/11/3.
//
#include "vector"

// 我们观察戳气球的操作，发现这会导致两个气球从不相邻变成相邻，使得后续操作难以处理。
// 于是我们倒过来看这些操作，假设 mid 是最后一个戳爆的
// 自顶向下，带记忆的回溯
// dp[i][j] = nums[i]*nums[mid]*nums[j] + dp[i][mid] + dp[mid][j]
void top2down(std::vector<int> &nums, int i, int j, std::vector<std::vector<int>> &dp) {
  if (dp[i][j]!=-1) return;

  for (int idx = i + 1; idx < j; ++idx) {
	top2down(nums, i, idx, dp);
	top2down(nums, idx, j, dp);
	dp[i][j] = std::max(nums[i]*nums[idx]*nums[j] + dp[i][idx] + dp[idx][j], dp[i][j]);
  }
}

int maxCoins(std::vector<int> &nums) {
  int size = nums.size();
  if (size==0) return 0;
  if (size==1) return nums[0];
  if (size==2) return std::max(nums[0], nums[1]) + nums[0]*nums[1];

  std::vector<int> nums_copy(size + 2);
  size += 2;
  nums_copy[0] = 1;            // 设置左界限
  std::copy(nums.begin(), nums.end(), nums_copy.begin() + 1);
  nums_copy[size - 1] = 1;    // 设置右界限

  std::vector<std::vector<int>> dp(size, std::vector<int>(size, -1));
  for (int i = 0; i < size - 1; ++i) {
	dp[i][i + 1] = 0;
  }
  top2down(nums_copy, 0, size - 1, dp);

  return dp[0][size - 1];
}

// 自底向上 dp
// 还是定义 mid 为最后一个戳爆的气球
// dp[i][j] 表示戳爆 (i,j) 区间获得的最大金币数
// dp[i][j] = nums[i]*nums[mid]*nums[j] + dp[i][mid] + dp[mid][j]
int maxCoins_dp(std::vector<int> &nums) {
  int size = nums.size();
  if (size==0) return 0;
  if (size==1) return nums[0];
  if (size==2) return std::max(nums[0], nums[1]) + nums[0]*nums[1];

  std::vector<int> nums_copy(size + 2);
  size += 2;
  nums_copy[0] = 1;            // 设置左界限
  std::copy(nums.begin(), nums.end(), nums_copy.begin() + 1);
  nums_copy[size - 1] = 1;    // 设置右界限

  std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));
  for (int i = 1; i <= size - 2; ++i) {
	for (int j = 1; i + j < size; ++j) {
	  for (int k = j; k < i + j; ++k) {
		dp[j - 1][j + i] =
			std::max(dp[j - 1][i + j], nums_copy[j - 1]*nums_copy[k]*nums_copy[i + j] + dp[j - 1][k] + dp[k][j + i]);
	  }
	}
  }

  return dp[0][size - 1];
}