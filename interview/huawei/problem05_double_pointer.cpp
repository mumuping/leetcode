//
// Created by lp on 2023/4/26.
//
#include <unordered_map>
#include <vector>
#include <iostream>

/**
* 如果一个数组中的某个子段,其中出现次数最多的元素出现大于等于
* x 次， 被称为 x−子段。子段是数组中一个或多个连续元素组成的数组。
* 现在给定一个数组 a 和 x ,试问 a 有多少子段是 x−子段 。
*/

int Solve(const std::vector<int> &array, int x) {
  int left = 0, right = 0, res = 0;
  std::unordered_map<int, int> counts;
  int size = static_cast<int>(array.size());
  while (right < size) {
	++counts[array[right]];
	while (counts[array[right]] >= x) {
	  res += size - right;
	  --counts[array[left]];
	  ++left;
	}
	++right;
  }

  return res;
}

int main() {
  int num, x;
  std::cin >> num >> x;
  std::vector<int> array(num);
  for (auto &ar : array) {
	std::cin >> ar;
  }
  std::cout << Solve(array, x);
  return 0;
}