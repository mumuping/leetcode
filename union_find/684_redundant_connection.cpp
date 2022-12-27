//
// Created by lp on 2022/12/26.
//
#include "vector"
#include "numeric"

int find(std::vector<int> &sets, int x) {
  if (x==sets[x]) return x;
  sets[x] = find(sets, sets[x]);
  return sets[x];
}

bool Union(std::vector<int> &sets, int x, int y) {
  int parent_x = find(sets, x);
  int parent_y = find(sets, y);
  if (parent_x==parent_y) return false;
  sets[parent_x] = parent_y;
  return true;
}

std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
  int n = edges.size();
  if (n==0) return {};
  std::vector<int> sets(n + 1);
  std::iota(sets.begin(), sets.end(), 0);

  int x, y;
  for (int i = 0; i < n; ++i) {
	x = edges[i][0], y = edges[i][1];
	if (!Union(sets, x, y)) return {x, y};
  }
  return {};
}