//
// Created by lp on 2022/11/28.
//

#include "unordered_set"
#include "queue"
#include "vector"

// 最小堆
int nthUglyNumber(int n) {
  if (n==1) return 1;

  const std::vector<int> primes{2, 3, 5};
  std::unordered_set<long> duplicate;
  std::priority_queue<long, std::vector<long>, std::greater<long>> ugly_numbers;
  ugly_numbers.push(1);

  int i = 0;
  long tmp, next;
  while (i!=n) {
	++i;
	tmp = ugly_numbers.top();
	ugly_numbers.pop();
	for (const int &prime : primes) {
	  next = prime*tmp;
	  if (duplicate.count(next)==0) {
		duplicate.insert(next);
		ugly_numbers.push(next);
	  }
	}
  }

  return tmp;
}

// 动态规划
// dp[i] 表示第 i 个丑数
int nthUglyNumber_dp(int n) {
  if (n==1) return 1;

  int p2 = 1, p3 = 1, p5 = 1;
  std::vector<int> dp(n + 1);
  dp[1] = 1;

  int tmp2, tmp3, tmp5;
  for (int i = 2; i <= n; ++i) {
	tmp2 = 2*dp[p2];
	tmp3 = 3*dp[p3];
	tmp5 = 5*dp[p5];
	dp[i] = std::min(tmp2, std::min(tmp3, tmp5));
	if (dp[i]==tmp2) ++p2;
	if (dp[i]==tmp3) ++p3;
	if (dp[i]==tmp5) ++p5;
  }

  return dp[n];
}
