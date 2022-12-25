//
// Created by lp on 2022/12/8.
//
#include "unordered_map"
#include "string"

// 统计奇数个数
int longestPalindrome_(std::string s) {
  int counts[128]{0};
  for (const char &i : s) {
	++counts[i];
  }
  int count = 0;
  for (int i = 0; i < 128; ++i) {
	count += counts[i]%2;
  }

  return count==0 ? s.size() : (s.size() - count + 1);
}

int longestPalindrome(std::string s) {
  std::unordered_map<char, int> counts;
  for (int i = 0; i < s.size(); ++i) {
	++counts[s[i]];
  }

  int length = 0;
  for (const auto &count : counts) {
	if (count.second%2==0) length += count.second;
	else if (count.second > 2) length += count.second - 1;
  }

  if (length < s.size()) ++length;
  return length;
}