//
// Created by lp on 2022/12/29.
//
#include "vector"
#include "queue"

void bfs_findIsland(std::vector<std::vector<char>> &grid, int x, int y) {
  int m = grid.size(), n = grid[0].size();
  std::queue<std::pair<int, int>> q;
  q.push({x, y});
  grid[x][y] = '0';
  char directions[5] = {-1, 0, 1, 0, -1};
  int next_x, next_y;
  while (!q.empty()) {
	x = q.front().first, y = q.front().second;
	q.pop();
	for (char i = 0; i < 4; ++i) {
	  next_x = x + directions[i], next_y = y + directions[i + 1];
	  if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && grid[next_x][next_y]=='1') {
		q.push({next_x, next_y});
		grid[next_x][next_y] = '0';	// 这里找到后应该第一时间设置为 '0'，否则会在 queue 中多次出现重复的点，超时
	  }
	}
  }
}

int numIslands(std::vector<std::vector<char>> &grid) {
  int num = 0;
  int n = grid.size(), m = grid[0].size();
  for (int i = 0; i < n; ++i) {
	for (int j = 0; j < m; ++j) {
	  if (grid[i][j]=='1') {
		bfs_findIsland(grid, i, j);
		++num;
	  }
	}
  }
  return num;
}