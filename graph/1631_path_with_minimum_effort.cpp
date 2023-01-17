#include "climits"
#include "cmath"
#include "queue"
#include "vector"

// 最小堆版本的 dijsktra 算法
class Comp {
 private:
  using type_of_priority_queue = std::pair<std::pair<int, int>, int>;
 public:
  bool operator()(const type_of_priority_queue &lhs, const type_of_priority_queue &rhs) {
    return lhs.second > rhs.second;
  }
};

int minimumEffortPath(std::vector<std::vector<int>> &heights) {
  int row = heights.size();
  if (row == 0) return 0;
  int col = heights[0].size();
  if (col == 0) return 0;

  if (row == 1) {
    int minimum_effort = 0;
    for (int i = 1; i < col; ++i) {
      minimum_effort =
          std::max(minimum_effort, heights[0][i] - heights[0][i - 1]);
    }
    return minimum_effort;
  }

  using type_of_priority_queue = std::pair<std::pair<int, int>, int>;
  std::vector<std::vector<int>> efforts(row, std::vector<int>(col, INT_MAX));
  std::priority_queue<type_of_priority_queue,
                      std::vector<type_of_priority_queue>, Comp>
      q;
  const int directions[5] = {-1, 0, 1, 0, -1};
  efforts[0][0] = 0;
  q.push(std::make_pair(std::make_pair(0, 0), 0));

  std::pair<int, int> point, next_point;
  int effort, height_between_neighbor;
  while (!q.empty()) {
    point = q.top().first;
    effort = q.top().second;
    if (point.first == row - 1 && point.second == col - 1) return effort;
    q.pop();
    if (effort > efforts[point.first][point.second]) continue;

    for (int i = 0; i < 4; ++i) {
      next_point.first = point.first + directions[i];
      next_point.second = point.second + directions[i + 1];

      if (next_point.first >= 0 && next_point.first < row &&
          next_point.second >= 0 && next_point.second < col) {
        height_between_neighbor =
            std::max(std::abs(heights[next_point.first][next_point.second] -
                         heights[point.first][point.second]),
                     efforts[point.first][point.second]);
        if (height_between_neighbor <
            efforts[next_point.first][next_point.second]) {
          efforts[next_point.first][next_point.second] =
              height_between_neighbor;
          q.push(std::make_pair(next_point, height_between_neighbor));
        }
      }
    }
  }

  return -1;
}