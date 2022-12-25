//
// Created by lp on 2022/11/10.
//
#include "vector"

int singleNumber(std::vector<int> &nums) {
  int size = nums.size();
  if (size==0) return 0;

  int number = nums[0];
  for (int i = 1; i < size; ++i) {
	number ^= nums[i];
  }

  return number;
}

int singleNumber_(std::vector<int> &nums) {
  if (nums.size()==0) return 0;

  int number = 0;
  for (const auto &i : nums) {
	number ^= i;
  }

  return number;
}