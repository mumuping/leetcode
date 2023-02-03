//
// Created by lp on 2023/2/3.
//
#include "string"
#include "vector"
#include "unordered_map"
#include "algorithm"

// 参考题 392
int numMatchingSubseq(std::string s, std::vector<std::string> &words) {
  int length_of_s = s.size(), num_of_words = words.size();
  std::unordered_map<char, std::vector<int>> c2index;
  for (int i = 0; i < length_of_s; ++i) {
	c2index[s[i]].push_back(i);
  }

  int num = 0, index = 0;
  for (int i = 0; i < num_of_words; ++i) {
	index = 0;
	int j = 0;
	for (; j < words[i].size(); ++j) {
	  auto iter = std::lower_bound(c2index[words[i][j]].begin(),
								   c2index[words[i][j]].end(),
								   index);
	  if (iter==c2index[words[i][j]].end()) break;
	  index = *iter + 1;
	}
	if (j==words[i].size()) ++num;
  }
  return num;
}