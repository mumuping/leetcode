//
// Created by lp on 2022/10/23.
//
#include "string"
#include "vector"

// 令 dp[i][j] 表示将第一个字符串到位置 i 为止，和第二个字符串到位置 j 为止，最多需要几步编辑
// 则当第 i 位和第 j 位对应的字符相同时，dp[i][j]=dp[i-1][j-1]
// 当二者对应的字符不同时，dp[i][j]=min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])+1
int minDistance(std::string word1, std::string word2) {
  int size_word1 = word1.size(), size_word2 = word2.size();
  if (size_word1==0) return size_word2;
  if (size_word2==0) return size_word1;

  // 这里最大值设置为 std::max(size_word1, size_word2)
  // 因为最大的编辑距离就是两者最大的长度
  std::vector<std::vector<int>> dp(size_word1 + 1,
								   std::vector<int>(size_word2 + 1, std::max(size_word1, size_word2)));
  dp[0][0] = 0;
  for (int i = 1; i <= size_word2; ++i)
	dp[0][i] = i;
  for (int i = 1; i <= size_word1; ++i)
	dp[i][0] = i;

  for (int i = 1; i <= size_word1; ++i) {
	for (int j = 1; j <= size_word2; ++j) {
	  if (word1[i - 1]==word2[j - 1]) {
		dp[i][j] = dp[i - 1][j - 1];
	  } else {
		dp[i][j] = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
	  }
	}
  }

  return dp[size_word1][size_word2];
}

// 当然也可以进行空间压缩，
// 若使用两行
// 注意一定要初始化
int minDistance_compression(std::string word1, std::string word2) {
  int size_word1 = word1.size(), size_word2 = word2.size();
  if (size_word1==0) return size_word2;
  if (size_word2==0) return size_word1;

  std::vector<int> dp[2];
  dp[0].resize(size_word2 + 1, std::max(size_word1, size_word2));
  dp[1].resize(size_word2 + 1, std::max(size_word1, size_word2));
  // 初始化
  for (int i = 0; i <= size_word2; ++i)
	dp[0][i] = i;
  dp[1][0] = 1;

  for (int i = 1; i <= size_word1; ++i) {
	for (int j = 1; j <= size_word2; ++j) {
	  if (word1[i - 1]==word2[j - 1]) {
		dp[1][j] = dp[0][j - 1];
	  } else {
		dp[1][j] = std::min(std::min(dp[0][j - 1], dp[0][j]), dp[1][j - 1]) + 1;
	  }
	}
	dp[0].swap(dp[1]);
	// 处理两种特殊情况
	dp[0][0] = i;
	dp[1][0] = i + 1;
  }

  return dp[0][size_word2];
}

// 当然一行加一个变量也可以
int minDistance_compression_(std::string word1, std::string word2) {
  int size_word1 = word1.size(), size_word2 = word2.size();
  if (size_word1==0) return size_word2;
  if (size_word2==0) return size_word1;

  std::vector<int> dp(size_word2 + 1, 0);
  // 初始化
  for (int i = 0; i <= size_word2; ++i)
	dp[i] = i;

  int left_upper_of_j = 0;
  int tmp;
  for (int i = 1; i <= size_word1; ++i) {
	left_upper_of_j = dp[0];
	dp[0] = i;
	for (int j = 1; j <= size_word2; ++j) {
	  if (word1[i - 1]==word2[j - 1]) {
		tmp = dp[j];				// 先记录左上方的值
		dp[j] = left_upper_of_j;	// 更新当前值
		left_upper_of_j = tmp;		// 新的左上方的值
	  } else {
		tmp = dp[j];
		dp[j] = std::min(std::min(dp[j - 1], dp[j]), left_upper_of_j) + 1;
		left_upper_of_j = tmp;
	  }
	}
  }

  return dp[size_word2];
}