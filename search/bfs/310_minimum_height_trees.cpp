//
// Created by lp on 2022/10/15.
//
#include "vector"
#include "queue"

// 分别用 dfs 和 bfs
int bfs(int start_node,
		std::vector<std::vector<int>> &adjacent,
		std::vector<int> &parent) {
  std::queue<int> que;
  que.push(start_node);
  std::vector<bool> is_visited(adjacent.size(), false);    // 节点访问标志
  is_visited[start_node] = true;
  parent[start_node] = -1;    // 开始节点父节点为空

  int node;
  int i;
  while (!que.empty()) {
	node = que.front();
	que.pop();
	for (i = 0; i < adjacent[node].size(); ++i) {
	  if (!is_visited[adjacent[node][i]]) {
		is_visited[adjacent[node][i]] = true;
		que.push(adjacent[node][i]);
		parent[adjacent[node][i]] = node;
	  }
	}
  }
  return node;
}

void _dfs(int node,
		  std::vector<std::vector<int>> &adjacent,
		  std::vector<int> &parent,
		  std::vector<int> &distance) {
  for (int i = 0; i < adjacent[node].size(); ++i) {
	if (distance[adjacent[node][i]]==-1) {
	  parent[adjacent[node][i]] = node;
	  distance[adjacent[node][i]] = distance[node] + 1;
	  _dfs(adjacent[node][i], adjacent, parent, distance);
	}
  }
}

int dfs(int start_node, std::vector<std::vector<int>> &adjacent, std::vector<int> &parent) {
  std::vector<int> distance(adjacent.size(), -1);    // 各点与 start_node 的距离
  distance[start_node] = 0;
  parent[start_node] = -1;
  _dfs(start_node, adjacent, parent, distance);    // 计算距离

  int max_distance = 0;
  int max_distance_node;
  for (int i = 0; i < adjacent.size(); ++i) {
	if (max_distance < distance[i]) {
	  max_distance = distance[i];
	  max_distance_node = i;
	}
  }
  return max_distance_node;
}

std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>> &edges) {
  if (n==1) return {0};

  // 建立邻接表
  std::vector<std::vector<int>> adjacent(n);
  for (int i = 0; i < edges.size(); ++i) {
	adjacent[edges[i][0]].push_back(edges[i][1]);
	adjacent[edges[i][1]].push_back(edges[i][0]);
  }

  std::vector<int> parent(n, -1);                // 保存树中最长路径中节点的父节点

  // 选择任意一个点，广度优先找到其最深节点
  int deepest_0 = bfs(0, adjacent, parent);
  // 再根据这个最深的节点找到它相应的最深的节点，即为整棵树最长的路径
  int deepest_1 = bfs(deepest_0, adjacent, parent);

  // 再把这个路径表示出来，找到其中间值即可
  std::vector<int> path;
  int node = deepest_1;
  path.push_back(node);
  while (parent[node]!=-1) {
	path.push_back(parent[node]);
	node = parent[node];
  }

  int length_of_path = path.size();
  if (length_of_path%2==0) {
	return {path[length_of_path/2 - 1], path[length_of_path/2]};
  } else {
	return {path[length_of_path/2]};
  }
}