//
// Created by lp on 2022/9/29.
//

#include "vector"

void select_sort(std::vector<int> &nums) {
  int mid = 0;
  for (int i = 0; i < nums.size() - 1; ++i) {
	mid = i;
	for (int j = i + 1; j < nums.size(); ++j) {
	  if (nums[mid] > nums[j])mid = j;
	}
	std::swap(nums[i], nums[mid]);
  }
}