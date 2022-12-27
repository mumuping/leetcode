//
// Created by lp on 2022/12/25.
//
#include "vector"
#include "queue"

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