//
// Created by lp on 2022/10/29.
//
#include "vector"

// dp
// 将题目变形：在每个元素前添加 + 或者 -，假设总的元素和为 sum，
// 添加 - 的元素和为 negative，则添加 + 的元素和为 sum-negative，
// 则 target=sum-negative-negative，则 negative=(sum-target)/2
// 因此我们只要在数组中找到和为 negative 的个数就行。
// 此外如果 negative 不是非负偶数，则直接返回 0，说明找不到
int findTargetSumWays(std::vector<int> &nums, int target) {
  int size = nums.size();
  if (size==0) return 0;
  if (size==1) return nums[0]==target || -nums[0]==target;

  int sum = 0;
  for (int i = 0; i < size; ++i) {
	sum += nums[i];
  }
  if (sum < target || (sum - target)%2!=0) return 0;

  int negative = (sum - target)/2;
  std::vector<std::vector<int>> dp(size + 1, std::vector<int>(negative + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= size; ++i) {
	dp[i][0] = 1;
	for (int j = 0; j <= negative; ++j) {    // negative 可能为 0，因此要从 0 开始
	  if (nums[i - 1] > j) {
		dp[i][j] = dp[i - 1][j];
	  } else {
		dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
	  }
	}
  }

  return dp[size][negative];
}

// 压缩空间
int findTargetSumWays_compression(std::vector<int> &nums, int target) {
  int size = nums.size();
  if (size==0) return 0;
  if (size==1) return nums[0]==target || -nums[0]==target;

  int sum = 0;
  for (int i = 0; i < size; ++i) {
	sum += nums[i];
  }
  if (sum < target || (sum - target)%2!=0) return 0;

  int negative = (sum - target)/2;
  std::vector<int> dp(negative + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= size; ++i) {
	dp[0] = 1;
	for (int j = negative; j >= 0; --j) {
	  if (nums[i - 1] <= j) {
		dp[j] = dp[j] + dp[j - nums[i - 1]];
	  }
	}
  }

  return dp[negative];
}