#include "vector"
#include "queue"
#include "stack"

bool isBipartite(std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  if (n==0) return true;

  std::vector<char> color(n);
  std::queue<int> nodes;


/*  // 注意由于题目给出了此图可能是不连通的
  // 而下面方法只能由于连通图
  nodes.push(0);
  color[0] = 1;
  while (!nodes.empty()) {
	int node = nodes.front();
	nodes.pop();
	for (int neighbor : graph[node]) {
	  if (color[neighbor]==0) {
		nodes.push(neighbor);
		color[neighbor] = color[node]==1 ? 2 : 1;
	  } else {
		if(color[neighbor]==color[node]) return false;
	  }
	}
  }*/

  for (int i = 0; i < n; ++i) {
	if (color[i]==0) {
	  nodes.push(i);
	  color[i] = 1;
	}
	while (!nodes.empty()) {
	  int node = nodes.front();
	  nodes.pop();
	  for (int neighbor : graph[node]) {
		if (color[neighbor]==0) {
		  nodes.push(neighbor);
		  color[neighbor] = color[node]==1 ? 2 : 1;
		} else {
		  if (color[neighbor]==color[node]) return false;
		}
	  }
	}
  }

  return true;
}

// 此外也可以用dfs
bool isBipartite_dfs(std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  if (n==0) return true;

  std::vector<char> color(n);
  std::stack<int> nodes;

  for (int i = 0; i < n; ++i) {
	if (color[i]==0) {
	  nodes.push(i);
	  color[i] = 1;
	}
	while (!nodes.empty()) {
	  int node = nodes.top();
	  nodes.pop();
	  for (int neighbor : graph[node]) {
		if (color[neighbor]==0) {
		  nodes.push(neighbor);
		  color[neighbor] = color[node]==1 ? 2 : 1;
		} else {
		  if (color[neighbor]==color[node]) return false;
		}
	  }
	}
  }
  return true;
}