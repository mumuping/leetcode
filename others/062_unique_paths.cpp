//
// Created by lp on 2023/2/27.
//
#include "vector"

int uniquePaths(int m, int n) {
  if (m==1 || n==1) return 1;

  std::vector<std::vector<int>> path_counts(m + 1, std::vector<int>(n + 1, 0));
  path_counts[1][0] = 1;
  for (int i = 1; i <= m; ++i) {
	for (int j = 1; j <= n; ++j) {
	  path_counts[i][j] = path_counts[i - 1][j] + path_counts[i][j - 1];
	}
  }
  return path_counts[m][n];
}

int uniquePaths_(int m, int n) {
  if (m==1 || n==1) return 1;
  std::vector<int> path_counts(n, 1);
  for (int i = 1; i < m; ++i) {
	for (int j = 1; j < n; ++j) {
	  path_counts[j] += path_counts[j - 1];
	}
  }
  return path_counts[n - 1];
}

int uniquePaths_Comb(int m, int n) {
  long long ans = 1;
  for (int x = n, y = 1; y < m; ++x, ++y) {
	ans = ans*x/y;
  }
  return ans;
}