//
// Created by lp on 2023/2/8.
//
#include "vector"

int removeElement(std::vector<int> &nums, int val) {
  if (nums.empty()) return 0;

  int n = nums.size(), index_place = 0, index_search = 0;
  while (index_search < n) {
	if (nums[index_search]!=val) {
	  nums[index_place] = nums[index_search];
	  ++index_place;
	}
	++index_search;
  }
  return index_place;
}