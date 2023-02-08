//
// Created by lp on 2023/2/8.
//
#include "vector"

int removeDuplicates(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1) return n;

  int index_place = 1, index_search = 1;
  while (index_search < n) {
	if (nums[index_search]!=nums[index_search - 1]) {
	  nums[index_place] = nums[index_search];
	  ++index_place;
	}
	++index_search;
  }
  return index_place;
}