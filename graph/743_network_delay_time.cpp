#include "climits"
#include "queue"
#include "vector"

int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
  if (n <= 1) return 0;
  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
  for (const auto& it : times) {
    graph[it[0]].push_back({it[1], it[2]});
  }

  std::priority_queue<std::pair<int, int>> q;
  q.push({k, 0});
  std::vector<int> distance(n + 1, INT_MAX);
  distance[k] = 0;

  int to, time;
  int tmp;
  while (!q.empty()) {
    to = q.top().first;
    time = q.top().second;
    q.pop();
    if (time > distance[to]) continue;
    for (const auto& it : graph[to]) {
      tmp = distance[to] + it.second;
      if (tmp < distance[it.first]) {
        distance[it.first] = tmp;
        q.push({it.first, tmp});
      }
    }
  }

  tmp = -1;
  for (int i = 1; i <= n; ++i) {
    tmp = std::max(tmp, distance[i]);
  }

  return tmp == INT_MAX ? -1 : tmp;
}