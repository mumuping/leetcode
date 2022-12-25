//
// Created by lp on 2022/10/21.
//
#include "string"
#include "string.h"
#include "vector"

// 用递归的方法超时
bool recursive(const std::string &s, int level, const std::vector<std::string> &wordDict) {
  if (level==s.size()) return true;

  for (int i = 0; i < wordDict.size(); ++i) {
	if (level + wordDict[i].size() <= s.size() && s.substr(level, wordDict[i].size())==wordDict[i]) {
	  if (recursive(s, level + wordDict[i].size(), wordDict)) return true;
	}
  }
  return false;
}

// 改用 dp
bool dp(const std::string &s, const std::vector<std::string> &wordDict) {
  int s_size = s.size();
  bool *dp = new bool[s_size + 1];
  memset(dp, false, sizeof(false)*(s_size + 1));
  dp[0] = true;

  int word_length;
  for (int i = 0; i < s_size; ++i) {
	for (int j = 0; j < wordDict.size(); ++j) { // 每个位置以每个单词结束
	  word_length = wordDict[j].size();
	  if (i + 1 >= word_length &&
		  s.substr(i + 1 - word_length, word_length)==wordDict[j] &&
		  dp[i - word_length + 1]) {
		dp[i + 1] = true;
	  }
	}
  }

  bool ans = dp[s_size];
  delete[] dp;
  return ans;
}

bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
  // return recursive(s,0,wordDict);
  return dp(s, wordDict);
}