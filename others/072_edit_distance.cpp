//
// Created by 18315 on 2023/3/3.
//
#include "string"
#include "vector"
#include "numeric"

int minDistance(std::string word1, std::string word2) {
  if (word1.empty()) return word2.length();
  if (word2.empty()) return word1.length();

  int length1 = word1.length(), length2 = word2.length();
  std::vector<std::vector<int>> dp(length1 + 1, std::vector<int>(length2 + 1));
  std::iota(dp[0].begin(), dp[0].end(), 0);
  for (int i = 1; i <= length1; ++i) {
    dp[i][0] = i;
  }

  for (int i = 1; i <= length1; ++i) {
    for (int j = 1; j <= length2; ++j) {
      if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = std::min(dp[i - 1][j - 1],
                            std::min(dp[i][j - 1], dp[i - 1][j])) + 1;
    }
  }

  return dp[length1][length2];
}

int minDistance_(std::string word1, std::string word2) {
  if (word1.empty()) return word2.length();
  if (word2.empty()) return word1.length();

  int length1 = word1.length(), length2 = word2.length();
  std::vector<int> dp(length2 + 1);
  std::iota(dp.begin(), dp.end(), 0);
  int left_top_j, tmp;
  for (int i = 0; i < length1; ++i) {
    left_top_j = dp[0];
    dp[0] = i + 1;
    for (int j = 1; j <= length2; ++j) {
      if (word1[i] == word2[j - 1]) {
        tmp = dp[j];
        dp[j] = left_top_j;
        left_top_j = tmp;
      } else {
        tmp = dp[j];
        dp[j] = std::min(left_top_j, std::min(dp[j], dp[j - 1])) + 1;
        left_top_j = tmp;
      }
    }
  }
  return dp[length2];
}