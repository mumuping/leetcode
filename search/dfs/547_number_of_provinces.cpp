//
// Created by lp on 2022/10/3.
//
#include "vector"
#include "stack"

// 采用栈的方法
int findCircleNum(std::vector<std::vector<int>> &isConnected) {
  int size_isConnected = isConnected.size();
  if (size_isConnected==1) return 1;

  // 创建一个数组用于判断某个城市是否被访问过
  bool *is_visited = new bool[size_isConnected]();

  // 用栈来遍历某个城市所属的省份的城市
  std::stack<int> s;
  int provinces = 0;

  // 开始遍历所有城市
  int next_i = 0;
  for (int i = 0; i < size_isConnected; i++) {
	// 如果当前城市没有被访问过
	if (!is_visited[i]) {
	  s.push(i);
	  ++provinces;
	  is_visited[i] = true;
	  while (!s.empty()) {
		next_i = s.top();
		s.pop();
		for (int j = 0; j < size_isConnected; ++j) {
		  if (!is_visited[j] && next_i!=j && isConnected[next_i][j]) {
			is_visited[j] = true;
			s.push(j);
		  }
		}
	  }
	}
  }
  delete[] is_visited;
  return provinces;
}

void dfs_findCity(std::vector<std::vector<int>> &isConnected, bool isVisited[], int city) {
  int size_isConnected = isConnected.size();
  // 开始遍历与 city 相连的其他城市
  for (size_t i = 0; i < size_isConnected; i++) {
	// 如果该城市 i 没有访问过，且该城市和 city 是相连的
	// 则将该城市设置为 isVisited[i]=true;
	// 并递归的访问城市 i
	if (!isVisited[i] && isConnected[city][i]) {
	  isVisited[i] = true;
	  dfs_findCity(isConnected, isVisited, i);
	}
  }
}

// 采用递归的方式
int findCircleNum_(std::vector<std::vector<int>> &isConnected) {
  int size_isConnected = isConnected.size();
  if (size_isConnected==1)return 1;

  int provinces = 0;
  bool *isVisited = new bool[size_isConnected]();
  for (size_t i = 0; i < size_isConnected; i++) {
	if (!isVisited[i]) {
	  isVisited[i] = true;
	  ++provinces;
	  dfs_findCity(isConnected, isVisited, i);
	}
  }
  return provinces;
}