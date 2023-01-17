//
// Created by 18315 on 2023/1/17.
//

#include "vector"
#include "utility"
#include "queue"

// 朴素 dijsktra 算法
double maxProbability(int n, std::vector<std::vector<int>> &edges,
                      std::vector<double> &succProb, int start, int end) {
  std::size_t num_of_edges = edges.size();
  std::vector<std::vector<std::pair<int, double>>> graph(n);
  for (int i = 0; i < num_of_edges; ++i) {
    graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
    graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
  }

  std::vector<double> succProb_of_nodes(n, 0);
  std::vector<bool> visited(n, false);
  succProb_of_nodes[start] = 1;
  visited[start] = true;
  for (const auto &it : graph[start]) {
    succProb_of_nodes[it.first] = it.second;
  }

  int next;
  double weight;
  for (int i = 1; i < n; ++i) {
    next = -1;
    for (int j = 0; j < n; ++j) {
      if (!visited[j] && (next == -1 || succProb_of_nodes[next] < succProb_of_nodes[j]))
        next = j;
    }

    if (next == end) return succProb_of_nodes[end];
    visited[next] = true;
    for (const auto &it : graph[next]) {
      weight = succProb_of_nodes[next] * it.second;
      if (weight > succProb_of_nodes[it.first]) {
        succProb_of_nodes[it.first] = weight;
      }
    }
  }

  return 0;
}

// 采用最大堆优化
class Comp {
 public:
  bool operator()(const std::pair<int, double> &lhs,
                  const std::pair<int, double> &rhs) {
    return lhs.second < rhs.second;
  }
};

double maxProbability_maxHeap(int n, std::vector<std::vector<int>> &edges,
                              std::vector<double> &succProb, int start, int end) {
  std::vector<std::vector<std::pair<int, double>>> graph(n);
  for (int i = 0; i < edges.size(); ++i) {
    graph[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
    graph[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
  }

  std::vector<double> succProb_of_nodes(n, 0);
  succProb_of_nodes[start] = 1;
  std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>, Comp> q;
  q.emplace(start, 1);

  int node;
  double weight_of_node;
  while (!q.empty()) {
    node = q.top().first;
    weight_of_node = q.top().second;
    if (node == end) return weight_of_node;
    q.pop();

    if (weight_of_node < succProb_of_nodes[node]) continue;

    for (const auto &next : graph[node]) {
      double weight_of_next = next.second * succProb_of_nodes[node];
      if (succProb_of_nodes[next.first] < weight_of_next) {
        succProb_of_nodes[next.first] = weight_of_next;
        q.emplace(next.first, weight_of_next);
      }
    }
  }

  return 0;
}
