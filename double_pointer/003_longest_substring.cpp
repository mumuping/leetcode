//
// Created by lp on 2022/9/17.
//
#include "string"
#include "unordered_set"

/**
 * 滑动窗口
 * @param s
 * @return
 */
int lengthOfLongestSubstring(std::string s) {
  size_t size = s.size();
  std::unordered_set<char> set;
  int result = 0, left = 0;

  for (int i = 0; i < size; ++i) {
	while (set.find(s[i])!=set.end()) {	// 一直删除直到到达前面重复的元素出现的位置
	  set.erase(s[left]);
	  ++left;
	}
	set.insert(s[i]);
	result = std::max(result, i - left + 1);
  }
  return result;
}
