//
// Created by lp on 2023/2/27.
//
#include "vector"

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
  if (obstacleGrid.empty()) return 0;
  int m = obstacleGrid.size();
  if (obstacleGrid[0].empty()) return 0;
  int n = obstacleGrid[0].size();

  std::vector<std::vector<int>> paths_count(m + 1, std::vector<int>(n + 1, 0));
  paths_count[0][1] = 1;
  for (int i = 1; i <= m; ++i) {
	for (int j = 1; j <= n; ++j) {
	  if (obstacleGrid[i - 1][j - 1]==0) {
		paths_count[i][j] = paths_count[i - 1][j] + paths_count[i][j - 1];
	  }
	}
  }
  return paths_count[m][n];
}

int uniquePathsWithObstacles_(std::vector<std::vector<int>> &obstacleGrid) {
  if (obstacleGrid.empty()) return 0;
  int m = obstacleGrid.size();
  if (obstacleGrid[0].empty()) return 0;
  int n = obstacleGrid[0].size();

  std::vector<int> paths_count(n + 1, 0);
  paths_count[1] = 1;
  for (int i = 1; i <= m; ++i) {
	for (int j = 1; j <= n; ++j) {
	  if (obstacleGrid[i - 1][j - 1]==1) paths_count[j] = 0;
	  else paths_count[j] += paths_count[j - 1];
	}
  }

  return paths_count[n];
}