//
// Created by lp on 2022/9/23.
//

#include "vector"
#include "algorithm"

int findMinArrowShots(std::vector<std::vector<int>> &points) {
  std::sort(points.begin(), points.end(), [](const std::vector<int> &first, const std::vector<int> &second) {
	return first[1] < second[1];
  });

  int size_points = points.size();
  int pre = points[0][1];
  int count = 1;
  for (int i = 1; i < size_points; ++i) {
	if (pre < points[i][0]) {
	  ++count;
	  pre = points[i][1];
	}
  }

  return count;
}