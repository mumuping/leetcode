#include "algorithm"
#include "numeric"
#include "tuple"
#include "vector"

// kruskal
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

int minCostConnectPoints(std::vector<std::vector<int>>& points) {
  int n = points.size();
  if (n <= 1) return 0;

  std::vector<int> ancestor(n);
  std::iota(ancestor.begin(), ancestor.end(), 0);
  typedef std::tuple<int, int, int> edge;
  std::vector<edge> edges;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      edges.push_back({i, j,
                       std::abs(points[i][0] - points[j][0]) +
                           std::abs(points[i][1] - points[j][1])});
    }
  }

  std::sort(edges.begin(), edges.end(),
            [](edge& a, edge& b) { return std::get<2>(a) < std::get<2>(b); });

  int cost = 0, count = 1;
  int i = 0;
  while (count < n) {
    int point1 = std::get<0>(edges[i]), point2 = std::get<1>(edges[i]);
    if (!isConnected(ancestor, point1, point2)) {
      cost += std::get<2>(edges[i]);
      merge(ancestor, point1, point2);
      ++count;
    }
    ++i;
  }

  return cost;
}