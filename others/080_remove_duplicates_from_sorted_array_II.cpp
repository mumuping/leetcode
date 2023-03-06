//
// Created by lp on 2023/3/6.
//
#include "vector"

int removeDuplicates(std::vector<int> &sorted_nums) {
  if (sorted_nums.empty()) return 0;

  const int size = sorted_nums.size();
  if (size < 3) return size;
  int replace_position = 1, same_count = 1;
  for (int i = 1; i < size; ++i) {
	if (sorted_nums[i]==sorted_nums[replace_position - 1]) {
	  if (same_count==1) {
		sorted_nums[replace_position] = sorted_nums[i];
		++replace_position;
		++same_count;
	  }
	} else {
	  sorted_nums[replace_position] = sorted_nums[i];
	  same_count = 1;
	  ++replace_position;
	}
  }
  sorted_nums.erase(sorted_nums.begin() + replace_position, sorted_nums.end());
  return replace_position;
}

int removeDuplicates_(std::vector<int> &sorted_nums) {
  if (sorted_nums.empty()) return 0;

  const int size = sorted_nums.size();
  if (size < 3) return size;
  int slow = 2, fast = 2;
  while (fast < size) {
	if (sorted_nums[slow - 2]!=sorted_nums[fast]) {
	  sorted_nums[slow] = sorted_nums[fast];
	  ++slow;
	}
	++fast;
  }
  return slow;
}
