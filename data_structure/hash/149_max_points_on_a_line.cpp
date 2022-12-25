//
// Created by lp on 2022/11/20.
//
#include "vector"
#include "unordered_map"

int maxPoints(std::vector<std::vector<int>> &points) {
  int n = points.size();
  if (n <= 2) return n;

  std::unordered_map<double, int> hs;        // <斜率，点个数>
  int same_points = 0, non_slope = 0;
  int max_points = 0;
  for (int i = 0; i < n; ++i) {
	same_points = 0, non_slope = 0;
	for (int j = i; j < n; ++j) {
	  if (points[i][0]==points[j][0]) {        // x 轴相等
		if (points[i][1]==points[j][1]) {        // 重复点
		  ++same_points;
		} else {                                // 斜率不存在的点个数
		  ++non_slope;
		}
	  } else {
		++hs[((double)(points[i][1] - points[j][1]))/(points[i][0] - points[j][0])];
	  }
	}

	// 取最大值
	for (const auto element : hs) {
	  max_points = std::max(max_points, element.second + same_points);
	}
	max_points = std::max(max_points, non_slope + same_points);

	hs.clear();
  }

  return max_points;
}