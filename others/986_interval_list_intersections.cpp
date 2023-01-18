//
// Created by 18315 on 2023/1/18.
//
#include "vector"

std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> &firstList,
                                                   std::vector<std::vector<int>> &secondList) {
  const int length_first = firstList.size(), length_second = secondList.size();
  std::vector<std::vector<int>> res;
  int index_first = 0, index_second = 0;
  while (index_first < length_first && index_second < length_second) {
    if (firstList[index_first][1] < secondList[index_second][0]) {
      ++index_first;
    } else if (secondList[index_second][1] < firstList[index_first][0]) {
      ++index_second;
    } else {
      if (firstList[index_first][1] < secondList[index_second][1]) {
        res.push_back({std::max(firstList[index_first][0], secondList[index_second][0]), firstList[index_first][1]});
        ++index_first;
      } else {
        res.push_back({std::max(firstList[index_first][0], secondList[index_second][0]), secondList[index_second][1]});
        ++index_second;
      }
    }
  }

  return res;
}