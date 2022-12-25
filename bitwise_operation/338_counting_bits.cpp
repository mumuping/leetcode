//
// Created by lp on 2022/11/11.
//
#include "vector"

std::vector<int> countBits(int n) {
  if (n==0) return {0};
  if (n==1) return {0, 1};

  std::vector<int> res(n + 1);
  for (int i = 0; i <= n; ++i) {
	res[i] = __builtin_popcount(i);
  }

  return res;
}

// 该题也可以使用动态规划
std::vector<int> countBits_dp(int n) {
  if (n==0) return {0};
  if (n==1) return {0, 1};

  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
	// 如果 i 为奇数（最后一位为 1），则 dp[i]=dp[i-1]+1
	// 如果 i 为偶数（最后一位为 0），则 dp[i]=dp[i>>1]
	if ((i & 1)==1) {
	  dp[i] = dp[i - 1] + 1;
	} else { dp[i] = dp[i >> 1]; }
  }

  return dp;
}