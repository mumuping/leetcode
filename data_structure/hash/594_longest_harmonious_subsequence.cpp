//
// Created by lp on 2022/11/25.
//
#include "vector"
#include "unordered_map"
#include "algorithm"

int findLHS(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1) return 0;
  if (n==2) return abs(nums[0] - nums[1])==1 ? 2 : 0;

  int length = 0;
  std::unordered_map<int, int> m;
  for (int i = 0; i < n; ++i) ++m[nums[i]];

  for (const auto i : m) {
	if (m.count(i.first + 1) > 0)	// 注意这里不能写成 m[i.first+1] 因为会在 for 循环中更改迭代器的有效性
	  length = std::max(length, m[i.first + 1] + i.second);
  }

  return length;
}

// 当然也可以使用枚举，枚举每个元素 x 和 x+1
int findLHS_enum(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1) return 0;
  if (n==2) return abs(nums[0] - nums[1])==1 ? 2 : 0;

  // 先排序
  std::sort(nums.begin(), nums.end());
  // 采用类似于滑动窗口的方法进行计算
  int begin = 0;
  int length = 0;
  for (int end = 0; end < n; ++end) {
	while (nums[end] - nums[begin] > 1) ++begin;
	if (nums[end] - nums[begin]==1) length = std::max(length, end - begin + 1);
  }

  return length;
}