//
// Created by lp on 2022/9/30.
//

#include "vector"
#include "algorithm"
#include "unordered_map"

// 桶排序
std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> num_counts;

  // 遍历 nums，统计各元素的个数
  int max_counts = 0;    // 记录最大的个数
  for (int i = 0; i < nums.size(); ++i) {
	++num_counts[nums[i]];
	max_counts = std::max(max_counts, num_counts[nums[i]]);
  }

  // 定义每个桶
  std::vector<std::vector<int>> counts_number;
  counts_number.resize(max_counts + 1);
  // 将元素放入各自的桶中
  for (std::unordered_map<int, int>::iterator begin = num_counts.begin(); begin!=num_counts.end(); ++begin) {
	counts_number[begin->second].push_back(begin->first);
  }

  // 返回出现频率前 k 的元素
  std::vector<int> result;
  result.reserve(k);
  for (int i = max_counts; i >= 0; --i) {
	for (int j = 0; j < counts_number[i].size(); ++j) {
	  result.push_back(counts_number[i][j]);
	  --k;
	  if (k==0) return result;
	}
  }
  return result;
}

// 使用 pair
std::vector<int> topKFrequent_(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> map_of_num_count;
  int i = 0;
  for (; i < nums.size(); ++i) {
	++map_of_num_count[nums[i]];
  }

  int size_of_num = map_of_num_count.size();
  std::pair<int, int> *num_count = new std::pair<int, int>[size_of_num];
  i = 0;
  for (std::unordered_map<int, int>::iterator begin = map_of_num_count.begin(); begin!=map_of_num_count.end();
	   ++begin) {
	num_count[i].first = begin->first;
	num_count[i++].second = begin->second;
  }

  std::sort(num_count, num_count + size_of_num, [](std::pair<int, int> a, std::pair<int, int> b) {
	return a.second > b.second;
  });

  std::vector<int> result;
  result.reserve(k);
  i = 0;
  while (k > 0) {
	result.push_back(num_count[i++].first);
	--k;
  }

  delete[] num_count;
  return result;
}
