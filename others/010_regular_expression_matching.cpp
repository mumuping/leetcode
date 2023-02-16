//
// Created by 18315 on 2023/2/15.
//
#include "string"
#include "vector"

bool isMatch(std::string s, std::string p) {
  if (p.empty()) return s.empty();
  int size_s = s.size(), size_p = p.size();
  std::vector<std::vector<bool>> dp(size_s + 1, std::vector<bool>(size_p + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= size_p; ++i) {
    if (p[i - 1] == '*' && i >= 2)
      dp[0][i] = dp[0][i - 2];
  }

  for (int i = 1; i <= size_s; ++i) {
    for (int j = 1; j <= size_p; ++j) {
      if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
        dp[i][j] = dp[i - 1][j - 1];
      if (p[j - 1] == '*' && j >= 2) {
        if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
          dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
        else
          dp[i][j] = dp[i][j - 2];
      }
    }
  }
  return dp[size_s][size_p];
}