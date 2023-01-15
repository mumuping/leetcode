#include "climits"
#include "functional"
#include "iostream"
#include "queue"
#include "utility"
#include "vector"
/**
 * graph 表示邻接矩阵
 * 顶点编号从 0 开始
 */
std::vector<int> dijsktra(const std::vector<std::vector<int>>& graph,
                          int start) {
  int n = graph.size();
  if (n == 0) return {};
  std::vector<int> distance(n, 0x3f3f3f3f);
  distance[start] = 0;
  if (n == 1) return distance;

  std::vector<int> visited(n, false);
  visited[start] = true;
  for (int i = 0; i < n; ++i) {
    distance[i] = graph[start][i];
  }

  for (int i = 1; i < n; ++i) {
    int next = -1;
    for (int j = 0; j < n; ++j) {
      if (!visited[j] && (next == -1 || distance[j] < distance[next])) {
        next = j;
      }
    }
    visited[next] = true;
    for (int j = 0; j < n; ++j) {
      distance[j] = std::min(distance[j], distance[next] + graph[next][j]);
    }
  }

  return distance;
}

// 最小堆实现
// edges[i] = {from, to, weight}
// n 表示节点数
class Comp {
 public:
  bool operator()(const std::pair<int, int>& lhs,
                  const std::pair<int, int>& rhs) {
    return lhs.second > rhs.second;
  }
};

std::vector<int> dijsktra_heap(const std::vector<std::vector<int>>& edges,
                               int n, int start) {
  if (n == 1) return {0};
  std::vector<std::vector<std::pair<int, int>>> graph(n);
  for (int i = 0; i < edges.size(); ++i) {
    graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
  }

  std::vector<int> distance(n, INT_MAX);
  distance[start] = 0;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      Comp>
      q;
  q.emplace(start, 0);

  int next, weight;
  int tmp;
  while (!q.empty()) {
    next = q.top().first;
    weight = q.top().second;
    q.pop();
    if (distance[next] < weight) continue;
    for (const auto& it : graph[next]) {
      tmp = weight + it.second;
      if (tmp < distance[it.first]) {
        distance[it.first] = tmp;
        q.push({it.first, tmp});
      }
    }
  }

  return distance;
}
