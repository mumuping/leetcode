//
// Created by lp on 2022/10/19.
//
#include "algorithm"
#include "cmath"

// dp
// f(n)=min( f(n-1^2), f(n-2^2), f(n-3^2), ..., f(n-i^2)) 其中 n-i^2 >=0
int numSquares(int n) {
  int *dp = new int[n + 1];
  dp[0] = 0;

  int tmp = 0x3f3f3f3f;
  for (int i = 1; i <= n; ++i) {
	tmp = 0x3f3f3f3f;
	for (int j = 1; i >= j*j; ++j) {
	  tmp = std::min(tmp, dp[i - j*j]);
	}
	dp[i] = tmp + 1;
  }

  delete[] dp;
  return tmp + 1;
}

// 数学方法

// 判断是否为完全平方数
bool isPerfectSquare(int x) {
  int y = sqrt(x);
  return y*y==x;
}

// 判断是否能表示为 4^k*(8m+7)
bool checkAnswer4(int x) {
  while (x%4==0) {
	x /= 4;
  }
  return x%8==7;
}

int numSquares_math(int n) {
  if (isPerfectSquare(n)) {
	return 1;
  }
  if (checkAnswer4(n)) {
	return 4;
  }
  for (int i = 1; i*i <= n; i++) {
	int j = n - i*i;
	if (isPerfectSquare(j)) {
	  return 2;
	}
  }
  return 3;
}