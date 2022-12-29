//
// Created by lp on 2022/12/29.
//
#include "vector"

void findPath(const std::vector<std::vector<int>> &graph,
			  std::vector<std::vector<int>> &paths,
			  std::vector<int> path,
			  int last,
			  int node) {
  path.push_back(node);
  if (node==last) {
	paths.push_back(path);
	path.pop_back();
	return;
  }
  for (int next : graph[node]) {
	findPath(graph, paths, path, last, next);
  }
  path.pop_back();
}

std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  if (n==0) return {};
  std::vector<std::vector<int>> paths;
  std::vector<int> path;
  findPath(graph, paths, path, n - 1, 0);
  return paths;
}