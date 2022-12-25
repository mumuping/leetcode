//
// Created by lp on 2022/10/28.
//
#include "string"
#include "vector"

int minDistance(std::string word1, std::string word2) {
  int size_1 = word1.size(), size_2 = word2.size();
  std::vector<std::vector<int>> dp(size_1 + 1, std::vector<int>(size_2 + 1, 0));
  for (int i = 0; i <= size_2; ++i) {
	dp[0][i] = i;
  }
  for (int i = 0; i <= size_1; ++i) {
	dp[i][0] = i;
  }

  for (int i = 1; i <= size_1; ++i) {
	for (int j = 1; j <= size_2; ++j) {
	  if (word1[i - 1]==word2[j - 1]) {
		dp[i][j] = dp[i - 1][j - 1];
	  } else {
		dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
	  }
	}
  }

  return dp[size_1][size_2];
}

// 压缩空间
int minDistance_compression(std::string word1, std::string word2) {
  int size_1 = word1.size(), size_2 = word2.size();
  std::vector<int> dp(size_2 + 1, 0);
  for (int i = 0; i <= size_2; ++i) {
	dp[i] = i;
  }

  int left_upper;
  for (int i = 1; i <= size_1; ++i) {
	left_upper = dp[0];
	dp[0] = i;
	for (int j = 1; j <= size_2; ++j) {
	  if (word1[i - 1]==word2[j - 1]) {
		std::swap(left_upper, dp[j]);
	  } else {
		left_upper = dp[j];
		dp[j] = std::min(dp[j], dp[j - 1]) + 1;
	  }
	}
  }

  return dp[size_2];
}