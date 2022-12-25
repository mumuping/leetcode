//
// Created by lp on 2022/10/15.
//

// dijkstra 算法
#include "bits/stdc++.h"
#include "algorithm"
#define MAX_DISTANCE 0x3f3f3f3f

// 这里测试用的五个顶点，若要更通用性，则可以把 weight 改为 int ** 类型
// 然后再使用 *((int*)weight+i*n+j)=value 模拟 weight[i][j]
// 当然使用 vector 更方便
void dijkstra(int (*weight)[5], int size, int shortest_distance[], int start_node) {
  if (size==1) {
	shortest_distance[0] = 0;
	return;
  }

  bool *visited = new bool[size]();    // 记录是否已经找到了最短路径
  visited[start_node] = true;
  shortest_distance[start_node] = 0;

  int max_dis = MAX_DISTANCE;
  int curr_node;
  // 每次计算出一个最短路径的节点
  for (size_t i = 1; i < size; ++i) {
	// 找到距离 start_node 的、未访问过的最短路径点
	curr_node = -1;
	max_dis = MAX_DISTANCE;
	for (size_t j = 0; j < size; ++j) {
	  if (!visited[j] && weight[j][start_node] < max_dis) {
		max_dis = weight[j][start_node];
		curr_node = j;
	  }
	}

	// 找到了当前最短路径的点
	visited[curr_node] = true;
	shortest_distance[curr_node] = max_dis;

	// 利用该点更新其他点到 start_node 的距离
	for (size_t j = 0; j < size; ++j) {
	  if (!visited[j] && weight[j][curr_node] + weight[curr_node][start_node] < weight[j][start_node]) {
		weight[start_node][j] = weight[j][start_node] = weight[j][curr_node] + weight[curr_node][start_node];
	  }
	}
  }
}

void test() {
  int weight[5][5] = {
	  {0, 4, MAX_DISTANCE, 2, MAX_DISTANCE},
	  {4, 0, 4, 1, MAX_DISTANCE},
	  {MAX_DISTANCE, 4, 0, 1, 3},
	  {2, 1, 1, 0, 7},
	  {MAX_DISTANCE, MAX_DISTANCE, 3, 7, 0}
  };
  int shortest_distance[5];

  dijkstra(weight, 5, shortest_distance, 0);

  std::for_each(shortest_distance, shortest_distance + 5, [&](int element) {
	std::cout << element << " ";
  });
}