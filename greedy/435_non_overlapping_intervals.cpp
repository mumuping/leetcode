//
// Created by lp on 2022/9/22.
//
#include "vector"
#include "algorithm"

int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
  int size_intervals = intervals.size();
  if (size_intervals==0)
	return 0;

  std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a,
												   const std::vector<int> &b) {
	return a[1] < b[1];
	// 注意对于 sort 函数，这里必须使用 < 或 >
	// 必须要求 strict weak order
	// 因为如果不这么做，可能会陷入到无限循环中
	// https://stackoverflow.com/questions/18291620/why-will-stdsort-crash-if-the-comparison-function-is-not-as-operator
  });

  int count = 0;
  int index_of_pre = 0;
  for (int i = 1; i < size_intervals; ++i) {
	if (intervals[i][0] < intervals[index_of_pre][1])
	  ++count;
	else
	  index_of_pre = i;
  }
  return count;
}

