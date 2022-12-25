//
// Created by lp on 2022/10/2.
//
#include "vector"
#include "stack"
/**
 * 该函数返回土地 [i,j] 所在岛屿的面积
 * @param grid 单元格
 * @param i 土地所在的行
 * @param j 土地所在的列
 * @return 岛屿的面积
 */
int dfs_AreaOfIsland(std::vector<std::vector<int>> &grid, int i, int j) {
  // 首先判断土地 [i,j] 是否合法
  if ((i < 0) || (i >= grid[0].size()) || (j < 0) || (j >= grid.size())) return 0;
  // 再判断该土地是否被访问过了
  if (grid[j][i]==0)return 0;

  // 先将当前土地设置为 0，表示该土地已经访问过了
  grid[j][i] = 0;
  // 开始遍历该岛屿的所有土地
  return 1 + dfs_AreaOfIsland(grid, i - 1, j)
	  + dfs_AreaOfIsland(grid, i, j - 1)
	  + dfs_AreaOfIsland(grid, i, j + 1)
	  + dfs_AreaOfIsland(grid, i + 1, j);
}

// 使用深度优先遍历
// 其中最主要的难点是如何判断某个土地是否被访问过了
// 这里选择的方法是：如果某个土地被访问了，那就将其设置为 0
int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
  // 从左到右，从上到下开始扫描
  int max_area = 0;
  for (int j = 0; j < grid.size(); ++j) {
	for (int i = 0; i < grid[0].size(); ++i) {
	  if (grid[j][i]) max_area = std::max(max_area, dfs_AreaOfIsland(grid, i, j));
	}
  }

  return max_area;
}

// 前面使用了递归形式的 dfs
// 这里再使用栈形式的 dfs
int maxAreaOfIsland_(std::vector<std::vector<int>> &grid) {
  int max_area = 0, island_area = 0;
  std::stack<std::pair<int, int>> s;
  int next_pos[5] = {0, 1, 0, -1, 0};

  // 从左到右，从上到下开始扫描
  // i 表示列，j 表示行
  int next_i, next_j;
  for (int i = 0; i < grid.size(); ++i) {
	for (int j = 0; j < grid[0].size(); ++j) {
	  if (grid[i][j]!=0) {
		s.push(std::make_pair(i, j));
		island_area = 1;
		grid[i][j] = 0;

		// 开始搜索某一块土地所属的岛屿面积
		while (!s.empty()) {
		  std::pair<int, int> pos = s.top();
		  s.pop();

		  // 遍历四个方向
		  for (int k = 0; k < 4; ++k) {
			next_i = pos.first + next_pos[k];
			next_j = pos.second + next_pos[k + 1];
			if (next_i >= 0 && next_i < grid.size() && next_j >= 0 && next_j < grid[0].size()
				&& grid[next_i][next_j]==1) {
			  s.push({next_i, next_j});
			  grid[next_i][next_j] = 0;
			  ++island_area;
			}
		  }
		}
		max_area = std::max(max_area, island_area);
	  }
	}
  }
  return max_area;
}