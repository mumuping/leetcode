//
// Created by lp on 2022/10/22.
//
#include "vector"

/**
 01 背包问题
 有 N 个物品和容量为 W 的背包，每个物品都有自己的体积 w 和价值 v，求拿哪些物品可以使得背包所装下物品的总价值最大。

 定义一个二维数组 dp
 存储最大价值，其中 dp[i][j] 表示前 i 件物品体积不超过 j 的情况下能达到的最大价值。在我们遍
 历到第 i 件物品时，在当前背包总容量为 j 的情况下，如果我们不将物品 i 放入背包，那么 dp[i][j]
 = dp[i-1][j]，即前 i 个物品的最大价值等于只取前 i-1 个物品时的最大价值；如果我们将物品 i 放
 入背包，假设第 i 件物品体积为 w，价值为 v，那么我们得到 dp[i][j] = dp[i-1][j-w] + v。我们只需
 在遍历过程中对这两种情况取最大值即可，总时间复杂度和空间复杂度都为 O(NW)。
 */
int knapsack_01(std::vector<int> &weights, std::vector<int> &value, int N, int W) {
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));
  for (int i = 1; i <= N; ++i) {
	for (int j = 1; j <= W; ++j) {
	  if (j >= weights[i - 1]) {
		dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + value[i]);
	  } else {
		dp[i][j] = dp[i - 1][j];
	  }
	}
  }
  return dp[N][W];
}

// 从上面的状态转移方程可以发现，dp[i][j] 只与上一层有关，因此可以压缩空间
int knapsack_01_compression(std::vector<int> &weights, std::vector<int> &value, int N, int W) {
  std::vector<int> dp(W + 1, 0);
  for (int i = 1; i <= N; ++i) {
	// 注意这里要从后往前遍历，如果从前往后遍历会覆盖掉要使用的数据
	for (int j = W; j >= weights[i - 1]; --j) {
	  dp[j] = std::max(dp[j], dp[j - weights[i - 1]] + value[i - 1]);
	}
  }
  return dp[W];
}