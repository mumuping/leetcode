//
// Created by lp on 2023/2/3.
//
#include "string"
#include "vector"
#include "unordered_map"
#include "algorithm"

// 遍历
bool isSubsequence(std::string s, std::string t) {
  int length_of_s = s.size(), length_of_t = t.size();
  if (length_of_t < length_of_s) return false;
  if (length_of_s==0) return true;

  int index_s = 0, index_t = 0;
  while (index_t < length_of_t) {
	if (s[index_s]==t[index_t]) ++index_s;
	if (index_s==length_of_s) return true;
	++index_t;
  }
  return false;
}

// 也可以使用二分
bool isSubsequence_binary(std::string s, std::string t) {
  int length_of_s = s.size(), length_of_t = t.size();
  if (length_of_t < length_of_s) return false;
  if (length_of_s==0) return true;

  std::unordered_map<char, std::vector<int>> c2index;
  for (int i = 0; i < length_of_t; ++i) {
	c2index[t[i]].push_back(i);
  }

  int index = 0;
  for (int i = 0; i < length_of_s; ++i) {
	auto iter = std::lower_bound(c2index[s[i]].begin(), c2index[s[i]].end(), index);
	if (iter==c2index[s[i]].end()) return false;
	else index = *iter + 1;
  }
  return true;
}