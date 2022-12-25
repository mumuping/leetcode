//
// Created by lp on 2022/9/22.
//
#include "vector"
#include "algorithm"

int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
  if (s.size()==0) return 0;

  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());

  int index_g = 0, index_s = 0;
  while (index_g < g.size() && index_s < s.size()) {
	if (s[index_s] >= g[index_g]) ++index_g;
	++index_s;
  }

  return index_g;
}