#include "numeric"
#include "string"
#include "vector"

int find(std::vector<int>& ancestors, int i) {
  if (i != ancestors[i]) {
    ancestors[i] = find(ancestors, ancestors[i]);
  }
  return ancestors[i];
}

inline void merge(std::vector<int>& ancestors, int i, int j) {
  if (i == j) return;
  ancestors[find(ancestors, i)] = find(ancestors, j);
}

inline bool isConnected(std::vector<int>& ancestors, int i, int j) {
  return find(ancestors, i) == find(ancestors, j);
}

bool equationsPossible(std::vector<std::string>& equations) {
  int n = equations.size();
  if (n == 0) return false;

  std::vector<int> ancestor(26);
  std::iota(ancestor.begin(), ancestor.end(), 0);

  std::vector<int> inequations;
  for (int i = 0; i < n; ++i) {
    if (equations[i][1] == '!') {
      inequations.push_back(i);
    } else {
      merge(ancestor, equations[i][0] - 'a', equations[i][3] - 'a');
    }
  }

  for (int i : inequations) {
    if (isConnected(ancestor, equations[i][0] - 'a', equations[i][3] - 'a'))
      return false;
  }

  return true;
}