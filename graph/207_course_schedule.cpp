//
// Created by lp on 2022/12/30.
//
#include "vector"
#include "unordered_map"
#include "memory"
#include "memory.h"

bool dfs(const std::vector<std::vector<int>> &graph, bool is_visited[], bool path[], int node) {
  if (path[node]) return true;
  if (is_visited[node]) return false;
  is_visited[node] = path[node] = true;
  for (int next : graph[node]) {
	if (dfs(graph, is_visited, path, next)) return true;
  }
  path[node] = false;
  return false;
}

bool canFinish_dfs(int numCourse, std::vector<std::vector<int>> &prerequisites) {
  if (numCourse < 2) return true;
  std::vector<std::vector<int>> graph(numCourse, std::vector<int>());
  for (const auto &it : prerequisites) {
	graph[it[1]].push_back(it[0]);
  }

  bool *is_visited = new bool[numCourse], *path = new bool[numCourse];
  memset(is_visited, false, sizeof(bool)*numCourse);
  memset(path, false, sizeof(bool)*numCourse);
  std::shared_ptr<bool> v(is_visited, [](bool *ptr) { delete[] ptr; });
  std::shared_ptr<bool> p(path, [](bool *ptr) { delete[] ptr; });
  for (int i = 0; i < numCourse; ++i) {
	if (!is_visited[i]) {
	  if (dfs(graph, is_visited, path, i)) return false;
	}
  }
  return true;
}

bool canFinish_degree(int numCourse, std::vector<std::vector<int>> &prerequisites) {
  if (numCourse < 2) return true;
  std::vector<int> in_degree(numCourse);
  std::unordered_map<int, std::vector<int>> pre;
  for (const auto it : prerequisites) {
	++in_degree[it[0]];
	pre[it[1]].push_back(it[0]);
  }

  std::vector<int> order_of_course;
  for (int i = 0; i < numCourse; ++i) {
	if (in_degree[i]==0) {
	  order_of_course.push_back(i);
	}
  }

  int index = 0;
  while (index < order_of_course.size()) {
	for (int it : pre[order_of_course[index]]) {
	  --in_degree[it];
	  if (in_degree[it]==0) order_of_course.push_back(it);
	}
	++index;
  }

  return index==numCourse;
}