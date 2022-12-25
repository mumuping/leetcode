//
// Created by lp on 2022/10/9.
//
#include "vector"
#include "stack"
#include "queue"

// 解决方法：先找到一个岛屿，然后一步一步向外延申，直到遇到第二座岛屿
// 即先用深度优先找完第一个岛屿，然后再从第一个岛屿周围的 0 开始向外延申，
// 用广度优先进行延申（广度优先常被用于搜索最短路径）
int shortestBridge(std::vector<std::vector<int>> &grid) {
  // 首先利用深度优先找完第一个岛屿，并把第一个岛屿周围的 0 记录
  int size_grid = grid.size();
  // 采用栈的方式进行深度优先
  std::stack<std::pair<int, int>> dfs_elements;
  std::queue<std::pair<int, int>> bfs_elements;    // 用于记录第一个岛屿周围的 0

  // 定义四个方向 0 -1 0 1 1 0 -1 0
  const char directions[] = {0, 1, 0, -1, 0};

  // 这里将访问过的值为 1 的点设置为 2，以标记之
  // 开始进行深度遍历
  std::pair<int, int> point;
  std::pair<int, int> next_point;
  bool is_dfs_finish = false;
  for (int i = 0; !is_dfs_finish && i < size_grid; ++i) {
	for (int j = 0; j < size_grid; ++j) {
	  // 找到了第一个为 1 的点的岛屿
	  if (grid[i][j]==1) {
		dfs_elements.push(std::pair<int, int>(i, j));
		// 开始 dfs
		while (!dfs_elements.empty()) {
		  point = dfs_elements.top();
		  dfs_elements.pop();
		  // 查看 point 是否访问过
		  if (grid[point.first][point.second]!=2) {    // 表示 point 没有访问过
			// 标记 point 访问过
			grid[point.first][point.second] = 2;
			// 将 point 的四个方向的 0 放入到队列中，以便进行下一步广度优先
			for (char k = 0; k < 4; ++k) {
			  next_point.first = point.first + directions[k];
			  next_point.second = point.second + directions[k + 1];
			  if (next_point.first >= 0 && next_point.first < size_grid &&
				  next_point.second >= 0 && next_point.second < size_grid) {
				if (grid[next_point.first][next_point.second]==0) {
				  bfs_elements.push(next_point);
				  // 注意这里要把岛屿的周围 0 也要设置为 2
				  // 表示已经访问过了，否则会出现重复
				  grid[next_point.first][next_point.second] = 2;
				}
				if (grid[next_point.first][next_point.second]==1) dfs_elements.push(next_point);
			  }
			}
		  }
		}
		// 表示已经找完了第一个岛屿
		is_dfs_finish = true;	// 这里用于退出第一个 for 循环
		break;	// 这里用于推出第二个 for 循环
	  }
	}
  }

  // 开始进行广度优先搜索，
  // 延申“一圈”都将使 distance 加一，直到遇到下一个岛屿的 1
  int distance = 0;
  int current_length_of_queue; // 用以记录当前圈的长度
  while (!bfs_elements.empty()) {
	current_length_of_queue = bfs_elements.size();
	++distance;

	// 开始遍历一圈
	for (int i = 0; i < current_length_of_queue; ++i) {
	  point = bfs_elements.front();
	  bfs_elements.pop();
	  // 开始遍历四个方向
	  for (int j = 0; j < 4; ++j) {
		next_point.first = point.first + directions[j];
		next_point.second = point.second + directions[j + 1];
		if (next_point.first >= 0 && next_point.first < size_grid &&
			next_point.second >= 0 && next_point.second < size_grid) {
		  if (grid[next_point.first][next_point.second]==0) {
			bfs_elements.push(next_point);
			// 这里同上述深度优先，也要将其设置为访问过，否则会出现重复
			grid[next_point.first][next_point.second] = 2;
		  }
		  if (grid[next_point.first][next_point.second]==1) return distance;
		}
	  }
	}
  }

  return distance;
}