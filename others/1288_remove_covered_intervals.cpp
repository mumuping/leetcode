//
// Created by 18315 on 2023/1/18.
//

#include "vector"
#include "algorithm"

int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
  const int n = intervals.size();
  if (n <= 1) return n;
  std::sort(intervals.begin(), intervals.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs[0] < rhs[0]) return true;
    else if (lhs[0] == rhs[0]) return lhs[1] > rhs[1];
    else return false;
  });

  int end = intervals[0][1];
  int remove_count = 0;
  for (int i = 1; i < n; ++i) {
    if (intervals[i][1] <= end) ++remove_count;
    else end = intervals[i][1];
  }
  return n - remove_count;
}