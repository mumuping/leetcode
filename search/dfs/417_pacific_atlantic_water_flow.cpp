//
// Created by lp on 2022/10/4.
//
#include "vector"

// 逆向思考：如果要判断一个 cell 是否可以同时流进太平洋和大西洋，
// 那么就需要依次遍历所有的 cell，其复杂度显然是很高的。
// 但考虑如果从太平洋边和大西洋边往回走，若都能到达，则显然就是要寻找的 cell
void dfs_cell(const std::vector<std::vector<int>> &heights, bool **is_reachable, int i, int j) {
  // 这里我们保证 [i,j] 是可以到达的 cell
  is_reachable[i][j] = true;

  // 那么我们就需要遍历此 cell 的上下左右
  int next_i, next_j;
  const int directions[5] = {-1, 0, 1, 0, -1};
  for (int k = 0; k < 4; ++k) {
	next_i = i + directions[k];
	next_j = j + directions[k + 1];
	// 判断 [next_i,next_j] 是否合法
	if (next_i < 0 || next_i >= heights.size() || next_j < 0 || next_j >= heights[0].size()) continue;
	// 若 [next_i,next_j] 可达
	if (!is_reachable[next_i][next_j] && heights[i][j] <= heights[next_i][next_j]) {
	  dfs_cell(heights, is_reachable, next_i, next_j);
	}
  }
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights) {
  int row = heights.size(), col = heights[0].size();

  // 创建能否到达太平洋矩阵
  bool **is_reachable_pacific = new bool *[row];
  int i = 0;
  for (; i < row; ++i)
	is_reachable_pacific[i] = new bool[col]();

  // 创建能否到达大西洋矩阵
  bool **is_reachable_altantic = new bool *[row];
  for (i = 0; i < row; ++i)
	is_reachable_altantic[i] = new bool[col]();

  // 搜索能够从上边界流进太平洋的 cell
  for (i = 0; i < col; ++i)
	dfs_cell(heights, is_reachable_pacific, 0, i);
  // 搜索能够从左边界流进太平洋的 cell
  for (i = 0; i < row; ++i)
	dfs_cell(heights, is_reachable_pacific, i, 0);
  // 搜索能够从右边界流进大西洋的 cell
  for (i = 0; i < row; ++i)
	dfs_cell(heights, is_reachable_altantic, i, col - 1);
  // 搜索能够从下边界流进大西洋的 cell
  for (i = 0; i < col; ++i)
	dfs_cell(heights, is_reachable_altantic, row - 1, i);

  // 搜索能够同时满足流进太平洋和大西洋的 cell
  std::vector<std::vector<int>> cells;
  int j = 0;
  for (i = 0; i < row; ++i) {
	for (j = 0; j < col; ++j) {
	  if (is_reachable_altantic[i][j] && is_reachable_pacific[i][j])
		cells.push_back({i, j});
	}
  }

  // 请理内存，收尾工作
  for (i = 0; i < row; ++i) {
	delete[] is_reachable_altantic[i];
	delete[] is_reachable_pacific[i];
  }
  delete[] is_reachable_altantic;
  delete[] is_reachable_pacific;

  return cells;
}
