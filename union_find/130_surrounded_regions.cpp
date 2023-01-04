#include "numeric"
#include "vector"

int find(std::vector<int>& ancestor, int i) {
  if (i != ancestor[i]) {
    ancestor[i] = find(ancestor, ancestor[i]);
  }
  return ancestor[i];
}

inline void merge(std::vector<int>& ancestor, int i, int j) {
  ancestor[find(ancestor, i)] = ancestor[find(ancestor, j)];
}

inline bool isConnected(std::vector<int>& ancestor, int i, int j) {
  return find(ancestor, i) == find(ancestor, j);
}

void solve(std::vector<std::vector<char>>& board) {
  int m = board.size();
  if (m <= 2) return;
  int n = board[0].size();
  if (n <= 2) return;

  int dummy = m * n;
  std::vector<int> ancestor(dummy + 1);
  std::iota(ancestor.begin(), ancestor.end(), 0);

  for (int i = 0; i < n; ++i) {
    if (board[0][i] == 'O') merge(ancestor, i, dummy);
    if (board[m - 1][i] == 'O') merge(ancestor, n * (m - 1) + i, dummy);
  }
  for (int j = 0; j < m; ++j) {
    if (board[j][0] == 'O') merge(ancestor, n * j, dummy);
    if (board[j][n - 1] == 'O') merge(ancestor, n * (j + 1) - 1, dummy);
  }

  int directions[5]{-1, 0, 1, 0, -1};
  for (int i = 1; i < m - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (board[i][j] == 'O') {
        for (int k = 0; k < 4; ++k) {
          int x = i + directions[k];
          int y = j + directions[k + 1];
          if (board[x][y] == 'O') merge(ancestor, x * n + y, i * n + j);
        }
      }
    }
  }

  for (int i = 1; i < m - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (!isConnected(ancestor, i * n + j, dummy)) board[i][j] = 'X';
    }
  }
}