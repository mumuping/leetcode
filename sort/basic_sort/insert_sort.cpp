//
// Created by lp on 2022/9/29.
//

#include "vector"

void insert_sort(std::vector<int> &nums) {
  for (int i = 0; i < nums.size(); ++i) {
	for (int j = i; j > 0; --j) {
	  if (nums[j] < nums[j - 1])std::swap(nums[j], nums[j - 1]);
	}
  }
}