//
// Created by lp on 2022/11/5.
//
#include "cmath"
#include "vector"

class Solution {
 public:
  Solution(std::vector<int> &nums) : m_nums(nums) {}

  std::vector<int> reset() { return m_nums; }

  std::vector<int> shuffle() {
	int size = m_nums.size();
	if (size <= 1) return m_nums;

	std::vector<int> nums(m_nums);
	for (int i = 1; i < size; ++i) {
	  std::swap(nums[i], nums[rand()%(i + 1)]);
	}

	return nums;
  }

 private:
  std::vector<int> m_nums;

};