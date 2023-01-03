#include "numeric"
#include "queue"
#include "vector"

// 使用二分图

// dfs
bool partition(const std::vector<std::vector<int>>& graph,
               std::vector<bool>& group, std::vector<bool>& visited, int n) {
  visited[n] = true;
  for (const auto& it : graph[n]) {
    if (visited[it] && group[it] == group[n]) {
      return false;
    }
    if (!visited[it]) {
      group[it] = !group[n];
      if (!partition(graph, group, visited, it)) return false;
    }
  }
  return true;
}

bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {
  if (n < 1) return true;
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (const auto& it : dislikes) {
    graph[it[0]].push_back(it[1]);
    graph[it[1]].push_back(it[0]);
  }
  std::vector<bool> visited(n + 1, false), group(n + 1);
  group[1] = false;

  for (int i = 1; i <= n; ++i) {
    if (!visited[i] && !partition(graph, group, visited, i)) return false;
  }
  return true;
}

// bfs
bool parition(const std::vector<std::vector<int>>& graph) {
  std::queue<int> q;
  int n = graph.size();
  std::vector<bool> visited(n + 1, false), group(n + 1);

  int node;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      group[i] = true;
      q.emplace(i);
      while (!q.empty()) {
        node = q.front();
        q.pop();
        visited[node] = true;
        for (int neighbor : graph[node]) {
          if (visited[neighbor] && group[neighbor] == group[node]) return false;
          if (!visited[neighbor]) {
            group[neighbor] = !group[node];
            q.push(neighbor);
          }
        }
      }
    }
  }

  return true;
}

bool possibleBipartition_bfs(int n, std::vector<std::vector<int>>& dislikes) {
  if (n < 1) return true;
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (const auto& it : dislikes) {
    graph[it[0]].push_back(it[1]);
    graph[it[1]].push_back(it[0]);
  }

  return parition(graph);
}

int findAncestor(std::vector<int>& ancestor, int i) {
  if (i != ancestor[i]) {
    ancestor[i] = findAncestor(ancestor, ancestor[i]);
  }
  return ancestor[i];
}

inline void merge(std::vector<int>& ancestor, int i, int j) {
  ancestor[findAncestor(ancestor, i)] = findAncestor(ancestor, j);
}

// 并查集
bool possibleBipartition_union_find(int n,
                                    std::vector<std::vector<int>>& dislikes) {
  std::vector<std::vector<int>> graph(n + 1, std::vector<int>());
  for (const auto& it : dislikes) {
    graph[it[0]].push_back(it[1]);
    graph[it[1]].push_back(it[0]);
  }

  std::vector<int> ancestor(n + 1);
  std::iota(ancestor.begin(), ancestor.end(), 0);

  int ancestor_i, ancestor_dislike;
  for (int i = 1; i <= n; ++i) {
    ancestor_i = findAncestor(ancestor, i);
    for (int dislike : graph[i]) {
      ancestor_dislike = findAncestor(ancestor, dislike);
      if (ancestor_dislike == ancestor_i) return false;
      merge(ancestor, ancestor_dislike, graph[i][0]);
    }
  }

  return true;
}