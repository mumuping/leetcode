//
// Created by lp on 2022/10/22.
//
#include "vector"
#include "algorithm"
#include "numeric"

// 递归
// 在本测试用例中会超时
bool recursive(std::vector<int> &nums, int level, int target) {
  if (level==nums.size()) return false;

  for (int i = level; i < nums.size(); ++i) {
	if (nums[i] > target) return false;
	else if (nums[i]==target) return true;
	else {
	  if (recursive(nums, i + 1, target - nums[i])) return true;
	}
  }
  return false;
}

bool canPartition(std::vector<int> &nums) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum%2!=0) return false;
  sum = sum >> 1;
  std::sort(nums.begin(), nums.end());
  return recursive(nums, 0, sum);
}

// 本题等价于 0-1 背包问题，设所有数字和为 sum，我们的目标是选取一部分物品，使得它们
// 的总和为 sum/2。这道题不需要考虑价值，因此我们只需要通过一个布尔值矩阵来表示状态转移矩阵
bool canPartition_dp(std::vector<int> &nums) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum%2!=0) return false;

  sum >>= 1;
  // std::sort(nums.begin(), nums.end());	// 可以不用排序
  int size_nums = nums.size();
  std::vector<std::vector<bool>> dp(size_nums + 1, std::vector<bool>(sum + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= size_nums; ++i) {
	for (int j = 1; j <= sum; ++j) {
	  if (nums[i - 1] <= j) {
		dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - nums[i - 1]]);
	  } else {
		dp[i][j] = dp[i - 1][j];
	  }
	}
  }

  return dp[size_nums][sum];
}

// 同样根据状态转移方程可以压缩空间
bool canPartition_dp_compression(std::vector<int> &nums) {
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  if (sum%2!=0) return false;

  sum >>= 1;
  int size_nums = nums.size();
  std::vector<bool> dp(sum + 1, false);
  dp[0] = true;

  for (int i = 1; i < size_nums; ++i) {
	for (int j = sum; j >= nums[i - 1]; --j) {
	  dp[j] = (dp[j] || dp[j - nums[i - 1]]);
	}
  }

  return dp[sum];
}