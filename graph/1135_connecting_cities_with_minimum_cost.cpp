#include "algorithm"
#include "numeric"
#include "queue"
#include "tuple"
#include "utility"

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

// prim
class Comp {
 private:
  typedef std::tuple<int, int, int> t;

 public:
  bool operator()(const t& lhs, const t& rhs) const {
    return std::get<2>(lhs) < std::get<2>(rhs);
  }
};

inline void get_edges(
    const std::vector<std::vector<std::pair<int, int>>>& graph,
    const std::vector<bool>& in_mst,
    std::priority_queue<std::tuple<int, int, int>,
                        std::vector<std::tuple<int, int, int>>, Comp>& pq,
    int node) {
  for (const auto& it : graph[node]) {
    if (!in_mst[it.first]) {
      pq.push(std::make_tuple(node, it.first, it.second));
    }
  }
}

int minimumCost_prim(int N, std::vector<std::vector<int>>& connections) {
  int num_of_edges = connections.size();
  if (num_of_edges < N - 1) return -1;

  std::vector<std::vector<std::pair<int, int>>> graph(
      N + 1, std::vector<std::pair<int, int>>());
  for (const auto& edge : connections) {
    graph[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
    graph[edge[1]].push_back(std::make_pair(edge[0], edge[2]));
  }

  std::priority_queue<std::tuple<int, int, int>,
                      std::vector<std::tuple<int, int, int>>, Comp>
      pq;
  std::vector<bool> in_mst(N + 1, false);
  in_mst[1] = true;
  get_edges(graph, in_mst, pq, 1);

  std::tuple<int, int, int> edge;
  int to, weight = 0, num_of_nodes = 1;
  while (!pq.empty()) {
    edge = pq.top();
    pq.pop();
    to = std::get<1>(edge);
    if (!in_mst[to]) {
      in_mst[to] = true;
      ++num_of_nodes;
      weight += std::get<2>(edge);
      get_edges(graph, in_mst, pq, to);
    }
  }

  return num_of_nodes == N ? weight : -1;
}