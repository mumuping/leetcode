//
// Created by lp on 2022/12/10.
//
#include "string"
#include "vector"

// 第一种方法：遍历每个中心点，时间复杂度 O(n^2) 空间复杂度 O(1)
std::string longestPalindrome(std::string s) {
  int n = s.size();
  if (n==0) return {};
  if (n==1) return s;
  if (n==2) return s[0]==s[1] ? s : s.substr(0, 1);

  int longest_left, longest_length = 0;
  int left, right, length;
  for (int i = 0; i < n; ++i) {
	left = right = i;
	length = 0;
	while (left >= 0 && right < n && s[left]==s[right]) {
	  --left;
	  ++right;
	  length += 2;
	}
	--length;
	if (length > longest_length) {
	  longest_length = length;
	  longest_left = left < 0 ? 0 : left + 1;
	}

	if (i + 1 < n) {
	  left = i;
	  right = i + 1;
	  length = 0;
	  while (left >= 0 && right < n && s[left]==s[right]) {
		--left;
		++right;
		length += 2;
	  }
	  if (length > longest_length) {
		longest_length = length;
		longest_left = left < 0 ? 0 : left + 1;
	  }
	}
  }

  return s.substr(longest_left, longest_length);
}

// 第二种方法：动态规划 时间复杂度 O(n^2) 空间复杂度 O(n^2)
std::string longestPalindrome_dp(std::string s) {
  const int n = s.size();
  if (n==0) return {};
  if (n==1) return s;
  if (n==2) return s[0]==s[1] ? s : s.substr(0, 1);

  int longest = 1;
  int left_index = 0;
  std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
	dp[i][i] = true;
  }
  for (int i = 0; i < n - 1; ++i) {
	if (s[i]==s[i + 1]) {
	  dp[i][i + 1] = true;
	  longest = 2;
	  left_index = i;
	}
  }

  for (int length = 2; length < n; ++length) {
	for (int left = 0, right = left + length; right < n; ++left, right = left + length) {
	  if (dp[left + 1][right - 1] && s[left]==s[right]) {
		dp[left][right] = true;
		if (right - left + 1 > longest) {
		  left_index = left;
		  longest = right - left + 1;
		}
	  }
	}
  }
  return s.substr(left_index, longest);
}

// 第三种算法：Manacher 算法
std::string longestPalindrome_M(std::string s) {
  int n = s.size();
  if (n==0) return {};
  if (n==1) return s;
  if (n==2) return s[0]==s[1] ? s : s.substr(0, 1);

  std::string tmp("#");
  for (const char &i : s) {
	tmp += i;
	tmp += '#';
  }

  n = (n << 1) + 1;
  std::vector<int> dp(n);
  int max_length = 0, begin = 0;
  int center = 0, max_right = 0;
  for (int i = 0; i < n; ++i) {
	if (i < max_right) {
	  int mirror = (center << 1) - i;
	  dp[i] = std::min(dp[mirror], max_right - i);
	}

	int left = i - (dp[i] + 1);
	int right = i + (dp[i] + 1);
	while (left >= 0 && right < n && tmp[left]==tmp[right]) {
	  --left;
	  ++right;
	  ++dp[i];
	}

	if (i + dp[i] > max_right) {
	  center = i;
	  max_right = i + dp[i];
	}

	if (max_length < dp[i]) {
	  max_length = dp[i];
	  begin = (i - max_length)/2;
	}
  }

  return s.substr(begin, max_length);
}
