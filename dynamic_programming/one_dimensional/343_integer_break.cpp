//
// Created by lp on 2022/10/27.
//
#include "vector"

// dp[i]=max_(1<=j<i)(max(j*(i-j), j*dp[i-j))
// 将 i 拆分成 j 和 i−j 的和，且 i−j 不再拆分成多个正整数，此时的乘积是 j×(i−j)；
//将 i 拆分成 j 和 i−j 的和，且 i−j 继续拆分成多个正整数，此时的乘积是 j×dp[i−j]。
int integerBreak(int n) {
  std::vector<int> dp(n + 1, 0);

  int tmp = 0;
  for (int i = 2; i <= n; ++i) {
	tmp = 0;
	for (int j = 1; j < i; ++j) {
	  tmp = std::max(tmp, std::max(dp[i - j]*j, (i - j)*j));
	}
	dp[i] = tmp;
  }

  return dp[n];
}

