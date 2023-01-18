//
// Created by 18315 on 2023/1/18.
//
#include "vector"
#include "algorithm"

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
  const size_t n = intervals.size();
  if (n == 0) return {};
  if (n == 1) return {intervals[0]};

  std::sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs[0] < rhs[0]) return true;
    else if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];
    return false;
  });

  std::vector<std::vector<int>> res;
  int start = intervals[0][0], end = intervals[0][1];
  for (int i = 1; i < n; ++i) {
    if (end < intervals[i][0]) {
      res.push_back({start, end});
      start = intervals[i][0];
      end = intervals[i][1];
    } else if (end < intervals[i][1]) {
      end = intervals[i][1];
    }
  }
  res.push_back({start, end});

  return res;
}