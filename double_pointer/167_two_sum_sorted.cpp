//
// Created by lp on 2022/9/20.
//

#include "vector"

std::vector<int> twoSum(std::vector<int> &numbers, int target) {
  int left = 0, right = numbers.size() - 1;
  int sum = 0;

  while (left < right) {
	sum = numbers[left] + numbers[right];
	if (sum==target) return {left + 1, right + 1};
	else if (sum < target)++left;
	else --right;
  }
  return {0, 0};
}