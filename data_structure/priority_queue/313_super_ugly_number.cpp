//
// Created by lp on 2022/11/28.
//
#include "vector"
#include "climits"

// 采用最小堆会超时
// 因此采用动态规划
int nthSuperUglyNumber(int n, std::vector<int> &primes) {
  if (n==1) return 1;

  int size = primes.size();
  std::vector<long> dp(n + 1);
  std::vector<int> pointer(size, 1);
  dp[1] = 1;

  long min_tmp = LONG_MAX;
  for (int i = 2; i <= n; ++i) {
	min_tmp = LONG_MAX;
	for (int j = 0; j < size; ++j) {
	  min_tmp = std::min(min_tmp, primes[j]*dp[pointer[j]]);
	}
	dp[i] = min_tmp;
	for (int j = 0; j < size; ++j) {
	  if (min_tmp==primes[j]*dp[pointer[j]])
		++pointer[j];
	}
  }

  return dp[n];
}