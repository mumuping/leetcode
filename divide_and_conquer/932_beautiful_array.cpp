//
// Created by lp on 2022/11/2.
//
#include "vector"
#include "unordered_map"

void divide_conquer(int n, std::unordered_map<int, std::vector<int>> &map) {
  if (map.find(n)!=map.end()) {
	return;
  }

  if (n==1) {
	map[1].emplace_back(1);
  } else {
	// 分为奇偶两部分，利用仿射将主问题转化为左右两部分子问题
	divide_conquer((n + 1)/2, map);  // 奇
	divide_conquer(n/2, map);        // 偶
	// 再将奇偶两部分组合
	for (int i = 0; i < map[(n + 1)/2].size(); ++i) {
	  map[n].emplace_back(map[(n + 1)/2][i]*2 - 1);
	}
	for (int i = 0; i < map[n/2].size(); ++i) {
	  map[n].emplace_back(map[n/2][i]*2);
	}
  }
}

std::vector<int> beautifulArray(int n) {
  std::unordered_map<int, std::vector<int>> map;
  divide_conquer(n, map);

  return map[n];
}