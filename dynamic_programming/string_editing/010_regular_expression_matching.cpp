//
// Created by lp on 2022/10/24.
//
#include "string"
#include "vector"

// 定义一个二维数组 dp，其中 dp[i][j] 表示以 i 截止的字符串是否可以被以 j 截止的正则表达式匹配
// 然后再进行分类讨论，当遇到 * . 以及其他字符时的状态转移方程
bool isMatch(std::string s, std::string p) {
  int size_s = s.size(), size_p = p.size();
  std::vector<std::vector<bool>> dp(size_s + 1, std::vector<bool>(size_p + 1, false));

  // 一定要初始化
  dp[0][0] = true;
  for (int i = 1; i <= size_p; ++i) {    // s 为空字符串，遍历 p，遇到 * 时，dp[0][i]=dp[0][i-2]
	if (p[i - 1]=='*' && i - 2 >= 0)
	  dp[0][i] = dp[0][i - 2];
  }

  for (int i = 1; i <= size_s; ++i) {
	for (int j = 1; j <= size_p; ++j) {
	  if (s[i - 1]==p[j - 1] || p[j - 1]=='.') {
		dp[i][j] = dp[i - 1][j - 1];
	  } else {
		if (p[j - 1]=='*' && j - 2 >= 0) {
		  if ((p[j - 2]=='.') || p[j - 2]==s[i - 1])
			dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
		  else
			dp[i][j] = dp[i][j - 2];
		}
	  }
	}
  }

  return dp[size_s][size_p];
}
// 从状态转移方程可以看出，可以进行空间压缩