//
// Created by lp on 2022/10/24.
//
#include "vector"
#include "cmath"

// f(n) = min( f(n/2)+2, f(n/3)+3, ..., f(n/n)+n ) 均要求可以整除
// or f(n) = min( f(1)+n, f(2)+n/2, ..., f(j)+n/j ) 均要求可以整除
//
int minSteps(int n) {
  if (n==1) return 0;

  std::vector<int> dp(n + 1, 0);
  int mini = 0x3f3f3f3f;
  for (int i = 2; i <= n; ++i) {
	mini = 0x3f3f3f3f;
	for (int j = 2; j <= i; ++j) {
	  if (i%j==0) {
		mini = std::min(mini, dp[i/j] + j);
	  }
	}
	dp[i] = mini;
  }

//  // 上面的还可以简化
//  for (int i = 2; i <= n; ++i) {
//	dp[i] = 0x3f3f3f3f;
//	for (int j = 1; j*j <= i; ++j) {
//	  if (i%j==0) {
//		dp[i] = std::min(dp[i], dp[j] + i/j);
//		dp[i] = std::min(dp[i], dp[i/j] + j);
//	  }
//	}
//  }

  return dp[n];
}

int minSteps_(int n) {
  if (n==1) return 0;
  std::vector<int> dp(n + 1);
  int sqrt_n = sqrt(n);
  for (int i = 2; i <= n; ++i) {
	dp[i] = i;
	for (int j = 2; j <= sqrt_n; ++j) {
	  if (i%j==0) {
		dp[i] = dp[j] + dp[i/j];
		break;
	  }
	}
  }

  return dp[n];
}
