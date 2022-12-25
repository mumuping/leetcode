//
// Created by lp on 2022/11/8.
//
#include "vector"

int majorityElement(std::vector<int> &nums) {
  int size = nums.size();
  if (size==1) return nums[0];

  int element = nums[0];
  int count = 1;
  for (int i = 1; i < size; ++i) {
	if (nums[i]==element) {
	  ++count;
	} else {
	  --count;
	  if (count==0) {
		element = nums[i];
		count = 1;
	  }
	}
  }

  return element;
}