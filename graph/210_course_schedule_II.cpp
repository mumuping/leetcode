//
// Created by lp on 2022/12/25.
//
#include "vector"
#include "queue"
#include "algorithm"

// 方法一：入度
std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::vector<std::vector<int>> graph(numCourses);
  std::vector<int> degree(numCourses), res;
  for (const auto &require : prerequisites) {
	graph[require[1]].push_back(require[0]);
	++degree[require[0]];
  }

  std::queue<int> q;
  for (int i = 0; i < numCourses; ++i) {
	if (degree[i]==0)
	  q.push(i);
  }

  while (!q.empty()) {
	int course = q.front();
	q.pop();
	res.push_back(course);
	for (const auto &after : graph[course]) {
	  --degree[after];
	  if (degree[after]==0) {
		q.push(after);
	  }
	}
  }

  if (res.size()!=numCourses) return {};
  return res;
}

std::vector<int> findOrder_(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::vector<std::vector<int>> graph(numCourses);
  std::vector<int> degree(numCourses), res;
  for (const auto &require : prerequisites) {
	graph[require[1]].push_back(require[0]);
	++degree[require[0]];
  }

  for (int i = 0; i < numCourses; ++i) {
	if (degree[i]==0)
	  res.push_back(i);
  }

  int index = 0, course;
  while (1) {
	if (index >= res.size()) break;
	course = res[index];
	for (const int after : graph[course]) {
	  --degree[after];
	  if (degree[after]==0) {
		res.push_back(after);
	  }
	}
	++index;
  }

  if (res.size()!=numCourses) return {};
  return res;
}

// 方法二：拓扑排序，后序遍历的逆序
bool dfs(const std::vector<std::vector<int>> &graph, std::vector<bool> &path_for_cycle,
		 std::vector<bool> &is_visited, std::vector<int> &orders, int node) {
  if (path_for_cycle[node]) return true;
  if (is_visited[node]) return false;
  is_visited[node] = path_for_cycle[node] = true;
  for (int next : graph[node]) {
	if (dfs(graph, path_for_cycle, is_visited, orders, next)) return true;
  }
  orders.push_back(node);
  path_for_cycle[node] = false;
  return false;
}

std::vector<int> findOrder_topological_sort(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::vector<std::vector<int>> graph(numCourses, std::vector<int>());
  for (const auto it : prerequisites) {
	graph[it[1]].push_back(it[0]);
  }

  std::vector<bool> path_for_cycle(numCourses, false);
  std::vector<bool> is_visited(numCourses, false);
  std::vector<int> orders;
  for (int i = 0; i < numCourses; ++i) {
	if (!is_visited[i]) {
	  if (dfs(graph, path_for_cycle, is_visited, orders, i)) return {};
	}
  }

  std::reverse(orders.begin(), orders.end());
  return orders;
}