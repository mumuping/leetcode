//
// Created by 18315 on 2023/1/22.
//
#include "vector"
#include "climits"
#include "map"

bool isRectangleCover(std::vector<std::vector<int>> &rectangles) {
  std::map<std::pair<int, int>, int> dict; // 记录每个点出现的次数
  typedef long long LL;
  LL sum = 0; // 小矩形的面积和
  for (auto &x : R) // 左上角是(a, b)右下角是(c, d)
  {
    LL a = x[0], b = x[1], c = x[2], d = x[3];
    ++dict[{a, b}], ++dict[{a, d}];
    ++dict[{c, b}], ++dict[{c, d}];
    sum += (c - a) * (d - b); // 计算总面积, 可能爆int所以用long long来存
  }
  std::vector<std::vector<int>> res; // 计算一下每个点出现的次数，记录一下只出现一次的点
  for (auto &element : dict)
    if (element.second == 1)
      res.push_back({element.first.first, element.first.second});
    else if (element.second == 3) // 如果有点出现3次就不是
      return false;
    else if (element.second > 4)
      return false;
  if (res.size() != 4)  // 出现1次的点必须恰好是4个
    return false;
  return sum == (LL) (res[3][0] - res[0][0]) * (res[3][1] - res[0][1]);
}