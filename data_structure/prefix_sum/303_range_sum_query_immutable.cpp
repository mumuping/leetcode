//
// Created by lp on 2022/11/22.
//
#include "vector"
#include "numeric"

class NumArray {
 public:
  NumArray(std::vector<int> &nums) : m_data(nums) {}

  int sumRange(int left, int right) {
	if (left > right) return 0;
	if (0 <= left && right < m_data.size()) {
	  if (left==right) return m_data[right];
	  int sum = 0;
	  while (left <= right) {
		sum += m_data[left];
		++left;
	  }
	  return sum;
	}
	return 0;
  }

 private:
  std::vector<int> m_data;
};

// 使用前缀和
class NumArray_partial_sum {
 public:
  NumArray_partial_sum(std::vector<int> &nums) : m_data(nums), m_partial_sum(nums.size() + 1) {
	std::partial_sum(m_data.begin(), m_data.end(), m_partial_sum.begin() + 1);
  }

  int sumRange(int left, int right) {
	if (left > right) return 0;
	if (0 <= left && right < m_data.size()) {
	  if (left==right) return m_data[right];
	  return m_partial_sum[right + 1] - m_partial_sum[left];
	}
	return 0;
  }

 private:
  std::vector<int> m_data;
  std::vector<int> m_partial_sum;
};