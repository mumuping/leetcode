//
// Created by lp on 2022/12/4.
//
#include "string"
#include "unordered_map"

// 第一种双向映射
bool isIsomorphic(std::string s, std::string t) {
  int n = s.size();
  if (n==1) return true;

  std::unordered_map<char, char> s_map;
  std::unordered_map<char, char> t_map;
  for (int i = 0; i < n; ++i) {
	if ((s_map.count(s[i]) && s_map[s[i]]!=t[i]) ||
		(t_map.count(t[i]) && t_map[t[i]]!=s[i])) {
	  return false;
	} else {
	  s_map[s[i]] = t[i];
	  t_map[t[i]] = s[i];
	}
  }
  return true;
}

// 第二种记录两个字符串每个位置的字符第一次出现的位置
// 如果两个字符串中相同位置的字符与它们第一次出现的位置一样，
// 那么这两个字符串同构。
bool isIsomorphic_index(std::string s, std::string t) {
  int n = s.size();
  if (n==1) return true;

  int s_index[256]{0}, t_index[256]{0};
  for (int i = 0; i < n; ++i) {
	if (s_index[s[i]]!=t_index[t[i]]) return false;
	else {
	  s_index[s[i]] = t_index[t[i]] = i + 1;
	}
  }

  return true;
}