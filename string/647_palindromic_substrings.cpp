//
// Created by lp on 2022/12/5.
//
#include "vector"
#include "string"

int countSubstrings(std::string s) {
  int n = s.size();
  if (n <= 1) return n;
  if (n==2) return s[0]==s[1] ? 3 : 2;

  int count = 0;
  std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
	dp[i][i] = true;
	++count;
  }
  for (int i = 0, j = i + 1; j < n; ++i, ++j) {
	if (s[i]==s[j]) {
	  dp[i][j] = true;
	  ++count;
	}
  }

  for (int length = 2; length < n; ++length) {
	for (int i = 0, j = i + length; j < n; ++i, ++j) {
	  if (s[i]==s[j]) {
		dp[i][j] = dp[i + 1][j - 1];
		if (dp[i][j]) ++count;
	  }
	}
  }

  return count;
}

// 选中间点往两边扩展
int countSubstrings_mid(std::string s) {
  int n = s.size();
  if (n <= 1) return n;
  if (n==2) return s[0]==s[1] ? 3 : 2;

  int count = 0;
  int left, right;
  for (int i = 0; i < n; ++i) {
	left = right = i;    // 奇数
	while (left >= 0 && right < n && s[left]==s[right]) {
	  ++count;
	  --left;
	  ++right;
	}
	if (i < n - 1) {    // 偶数
	  left = i;
	  right = i + 1;
	  while (left >= 0 && right < n && s[left]==s[right]) {
		++count;
		--left;
		++right;
	  }
	}
  }

  return count;
}

// 可以优化上述方案
int countSubstrings_mid_(std::string s) {
  int n = s.size();
  if (n <= 1) return n;
  if (n==2) return s[0]==s[1] ? 3 : 2;

  int count = 0;
  int left, right;
  for (int i = 0; i < 2*n - 1; ++i) {
	left = i/2;
	right = left + i%2;
	while (left >= 0 && right < n && s[left]==s[right]) {
	  --left;
	  ++right;
	  ++count;
	}
  }

  return count;
}