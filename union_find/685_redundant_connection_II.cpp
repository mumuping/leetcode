//
// Created by lp on 2022/12/26.
//
#include "vector"
#include "numeric"

int find(std::vector<int> &ancestor, int x) {
  if (x==ancestor[x]) return x;
  ancestor[x] = find(ancestor, ancestor[x]);
  return ancestor[x];
}

void merge(std::vector<int> &ancestor, int x, int y) {
  ancestor[find(ancestor, x)] = find(ancestor, y);
}

std::vector<int> findRedundantDirectedConnection(std::vector<std::vector<int>> &edges) {
  int n = edges.size();
  std::vector<int> parent(n + 1), ancestor(n + 1);    // parent 用于检测冲突，ancestor 用于检测环路
  std::iota(parent.begin(), parent.end(), 0);
  std::iota(ancestor.begin(), ancestor.end(), 0);
  int conflict = -1, cycle = -1;
  int x, y;
  for (int i = 0; i < n; ++i) {
	x = edges[i][0], y = edges[i][1];
	if (parent[y]!=y) {
	  conflict = i;
	} else {
	  parent[y] = x;
	  if (find(ancestor, x)==find(ancestor, y)) {
		cycle = i;
	  } else {
		merge(ancestor, x, y);
	  }
	}
  }

  if (conflict < 0) {
	return {edges[cycle][0], edges[cycle][1]};
  } else {
	if (cycle < 0) {
	  return {edges[conflict][0], edges[conflict][1]};
	} else {
	  return {parent[edges[conflict][1]], edges[conflict][1]};
	}
  }
}