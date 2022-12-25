//
// Created by lp on 2022/10/18.
//
#include "vector"
#include "queue"

// 第一种方法：bfs
std::vector<std::vector<int>> bfs(const std::vector<std::vector<int>> &mat) {
  // 搜索到所有的 0 压入到队列中，然后再一层一层的往外延申
  int m = mat.size(), n = mat[0].size();
  std::vector<std::vector<int>> distance(m, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> zeros;

  int i, j;
  for (i = 0; i < m; ++i) {
	for (j = 0; j < n; ++j) {
	  if (mat[i][j]==0) {
		zeros.emplace(i, j);
		distance[i][j] = 0;
	  }
	}
  }

  // 开始 bfs 遍历
  std::pair<int, int> curr, next;
  int iter_directions;
  const int directions[]{1, 0, -1, 0, 1};
  while (!zeros.empty()) {
	curr = zeros.front();
	zeros.pop();
	for (iter_directions = 0; iter_directions < 4; ++iter_directions) {
	  next.first = curr.first + directions[iter_directions];
	  next.second = curr.second + directions[iter_directions + 1];
	  if (next.first >= 0 && next.first < m && next.second >= 0 && next.second < n
		  && distance[next.first][next.second]==-1) {
		distance[next.first][next.second] = distance[curr.first][curr.second] + 1;
		zeros.emplace(next);
	  }
	}
  }

  return distance;
}

// 第二种方法 dp
// 从左上到右下进行一次动态搜索，再从右下到左上进行一次动态搜索。两次动态搜索即可完成四个方向上的查找。
std::vector<std::vector<int>> dp(const std::vector<std::vector<int>> &mat) {
  int m = mat.size(), n = mat[0].size();
  std::vector<std::vector<int>> distance(m, std::vector<int>(n, 0x3f3f3f3f));

  int i, j;
  for (i = 0; i < m; ++i) {
	for (j = 0; j < n; ++j) {
	  if (mat[i][j]==0)
		distance[i][j] = 0;
	  else {
		if (j > 0) {
		  distance[i][j] = std::min(distance[i][j], distance[i][j - 1] + 1);
		}
		if (i > 0) {
		  distance[i][j] = std::min(distance[i][j], distance[i - 1][j] + 1);
		}
	  }
	}
  }

  for (i = m - 1; i >= 0; --i) {
	for (j = n - 1; j >= 0; --j) {
	  if (mat[i][j]==0)
		distance[i][j] = 0;
	  else {
		if (j < n - 1) {
		  distance[i][j] = std::min(distance[i][j], distance[i][j + 1] + 1);
		}
		if (i < m - 1) {
		  distance[i][j] = std::min(distance[i][j], distance[i + 1][j] + 1);
		}
	  }
	}
  }

  return distance;
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &mat) {
  return bfs(mat);
}