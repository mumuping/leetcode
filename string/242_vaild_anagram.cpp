//
// Created by lp on 2022/12/3.
//
#include "vector"
#include "string"

bool isAnagram(std::string s, std::string t) {
  if (s.size()!=t.size()) return false;
  std::vector<int> counts(26);
  for (int i = 0; i < s.size(); ++i) {
	++counts[s[i] - 'a'];
	--counts[t[i] - 'a'];
  }

  for (const int count : counts) {
	if (count!=0)return false;
  }

  return true;
}