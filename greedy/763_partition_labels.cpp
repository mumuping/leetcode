//
// Created by lp on 2022/9/24.
//
#include "vector"
#include "string"
#include "algorithm"

// 两次遍历
// 第一次获取每个字符最后出现的位置
// 第二次计算片段起始位置和结束位置
std::vector<int> partitionLabels(std::string s) {
  int s_size = s.size();
  if (s_size==1) return {1};

  // 第一次遍历
  int words_end[26];
  int i = 0;
  for (; i < s_size; ++i)
	words_end[s[i] - 'a'] = i;

  // 第二次遍历
  std::vector<int> result;
  int start = 0, end = 0;
  for (i = 0; i < s_size; ++i) {
	end = words_end[s[i] - 'a'] > end ? words_end[s[i] - 'a'] : end;
	if (i==end) {
	  result.push_back(end - start + 1);
	  start = i + 1;
	}
  }
  return result;
}