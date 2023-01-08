#include "algorithm"
#include "numeric"
#include "vector"

int find(std::vector<int>& ancestor, int i) {
  if (i != ancestor[i]) ancestor[i] = find(ancestor, ancestor[i]);
  return ancestor[i];
}

inline void merge(std::vector<int>& ancestor, int i, int j) {
  ancestor[find(ancestor, i)] = find(ancestor, j);
}

inline bool isConnected(std::vector<int>& ancestor, int i, int j) {
  return find(ancestor, i) == find(ancestor, j);
}

int minimumCost(int N, std::vector<std::vector<int>>& connections) {
  int num_of_edges = connections.size();
  if (num_of_edges < N - 1) return -1;

  std::vector<int> ancestor(N + 1);
  std::iota(ancestor.begin(), ancestor.end(), 0);
  std::sort(connections.begin(), connections.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {
              return a[2] < b[2];
            });

  int cost = 0, merge_edge_count = 0;
  for (int i = 0; i < num_of_edges; ++i) {
    if (!isConnected(ancestor, connections[i][0], connections[i][1])) {
      ++merge_edge_count;
      cost += connections[i][2];
      merge(ancestor, connections[i][0], connections[i][1]);
    }
    if (merge_edge_count == N - 1) break;
  }

  return merge_edge_count == N - 1 ? cost : -1;
}