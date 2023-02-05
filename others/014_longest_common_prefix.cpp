//
// Created by lp on 2023/2/5.
//
#include "string"
#include "vector"
#include "climits"

std::string longestCommonPrefix(std::vector<std::string> &strs) {
  int num = strs.size();
  if (num==0) return "";
  std::string common_prefix;

  size_t mini_length = strs[0].size();
  for (int i = 1; i < num; ++i) {
	mini_length = std::min(mini_length, strs[i].size());
  }

  for (int i = 0; i < mini_length; ++i) {
	char c = strs[0][i];
	for (int j = 1; j < num; ++j) {
	  if (strs[j][i]!=c) return common_prefix;
	}
	common_prefix += c;
  }
  return common_prefix;
}