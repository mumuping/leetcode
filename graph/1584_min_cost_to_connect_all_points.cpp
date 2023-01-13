#include "algorithm"
#include "numeric"
#include "queue"
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

// prim
class Comp {
 private:
  typedef std::pair<int, int> t;

 public:
  bool operator()(const t& lhs, const t& rhs) const {
    return rhs.second < lhs.second;
  }
};

inline void get_edges(
    const std::vector<std::vector<std::pair<int, int>>>& graph,
    const std::vector<bool>& in_mst,
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        Comp>& pq,
    int node) {
  for (const auto& edge : graph[node]) {
    if (!in_mst[edge.first]) {
      pq.push(edge);
    }
  }
}

int minCostConnectPoints_prim(std::vector<std::vector<int>>& points) {
  int n = points.size();
  if (n <= 1) return 0;

  std::vector<std::vector<std::pair<int, int>>> graph(
      n, std::vector<std::pair<int, int>>());
  int distance;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      distance = std::abs(points[i][0] - points[j][0]) +
                 std::abs(points[i][1] - points[j][1]);
      graph[i].push_back(std::make_pair(j, distance));
      graph[j].push_back(std::make_pair(i, distance));
    }
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      Comp>
      pq;
  std::vector<bool> in_mst(n, false);
  in_mst[0] = true;
  get_edges(graph, in_mst, pq, 0);

  int to, weight, weight_sum = 0;
  while (!pq.empty()) {
    to = pq.top().first;
    weight = pq.top().second;
    pq.pop();
    if (!in_mst[to]) {
      weight_sum += weight;
      in_mst[to] = true;
      get_edges(graph, in_mst, pq, to);
    }
  }

  return weight_sum;
}