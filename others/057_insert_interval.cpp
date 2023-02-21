//
// Created by lp on 2023/2/21.
//
#include "vector"
#include "algorithm"

std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
									 std::vector<int> &newInterval) {
  if (intervals.empty()) return {newInterval};
  auto start = std::lower_bound(
	  intervals.begin(),
	  intervals.end(),
	  newInterval,
	  [](const auto &element, const auto &value) {
		return element[1] < value[0];
	  });

  std::vector<std::vector<int>> res;
  if (start==intervals.end()) {
	res.insert(res.begin(), intervals.begin(), intervals.end());
	res.push_back(newInterval);
	return res;
  }

  std::vector<int> merge_interval(2);
  merge_interval[0] = std::min((*start)[0], newInterval[0]);
  auto finish = std::lower_bound(
	  intervals.begin(),
	  intervals.end(),
	  newInterval,
	  [](const auto &element, const auto &value) {
		return element[0] < value[1];
	  });

  if (finish==intervals.end()) {
	merge_interval[1] = std::max(intervals.back()[1], newInterval[1]);
  } else {
	if ((*finish)[0]==newInterval[1]) {
	  merge_interval[1] = (*finish)[1];
	  ++finish;
	} else {
	  if (finish==intervals.begin()) {
		res.push_back(newInterval);
		res.insert(res.end(), intervals.begin(), intervals.end());
		return res;
	  } else {
		merge_interval[1] = std::max((*std::prev(finish))[1], newInterval[1]);
	  }
	}
  }

  res.insert(res.end(), intervals.begin(), start);
  res.insert(res.end(), merge_interval);
  res.insert(res.end(), finish, intervals.end());
  return res;
}