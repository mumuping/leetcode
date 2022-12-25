//
// Created by lp on 2022/10/23.
//
#include "vector"

int coinChange(std::vector<int> &coins, int amount) {
  if (amount <= 0) return 0;

  int num_coins = coins.size();
  // 这里最大值设置为 amount + 1，因为最多的情况是全部为 1 组成和为 amount
  std::vector<std::vector<int>> dp(num_coins + 1, std::vector<int>(amount + 1, amount + 1));

  // 将每一行初始值设置为 0
  for (int i = 0; i <= num_coins; ++i)
	dp[i][0] = 0;

  for (int i = 1; i <= num_coins; ++i) {
	for (int j = 1; j <= amount; ++j) {
	  if (coins[i - 1] <= j) {
		dp[i][j] = std::min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
	  } else {
		dp[i][j] = dp[i - 1][j];
	  }
	}
  }

  return dp[num_coins][amount] > amount ? -1 : dp[num_coins][amount];
}

// 压缩空间
int coinChange_compression(std::vector<int> &coins, int amount) {
  if (amount <= 0) return 0;

  int num_coins = coins.size();
  std::vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;
  for (int i = 0; i < num_coins; ++i) {
	for (int j = coins[i]; j <= amount; ++j) {
	  dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
	}
  }

  return dp[amount] > amount ? -1 : dp[amount];
}