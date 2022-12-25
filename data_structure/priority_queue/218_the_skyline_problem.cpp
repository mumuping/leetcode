//
// Created by lp on 2022/11/17.
//
#include "vector"
#include "queue"
#include "algorithm"

std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int> > &buildings) {
  const int size_buildings = buildings.size();
  if (size_buildings==0) return {{}};

  // 先取出所有建筑的左右端点，并从小到大排序
  std::vector<int> points(size_buildings*2);
  int i = 0;
  for (const auto building : buildings) {
	points[i] = building[0];
	points[i + 1] = building[1];
	i += 2;
  }
  std::sort(points.begin(), points.end());

  // 再创建一个优先队列，该队列中存储的是包含该端点的 buildings
  // 可以优化为只存储《高度，右端点》
  // 以高度从大到小排序，若高度相同则按右端点从小到大排序
  auto comp = [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
	return a.first < b.first;
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> q(comp);

  i = 0;
  int tmp;
  std::vector<std::vector<int>> res;
  for (const auto point : points) {
	while (i < size_buildings && buildings[i][0] <= point) {
	  q.emplace(buildings[i][2], buildings[i][1]);    // 存储《高度，右端点》
	  ++i;
	}
	while (!q.empty() && q.top().second <= point) {
	  q.pop();
	}

	tmp = q.empty() ? 0 : q.top().first;
	if (res.size()==0 || res.back()[1]!=tmp) {    // 这是为了保证题目要求不连续
	  res.push_back({point, tmp});
	}
  }

  return res;
}