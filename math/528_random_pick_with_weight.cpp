//
// Created by lp on 2022/11/5.
//
#include "cmath"
#include "vector"
#include "numeric"
#include "algorithm"

// 利用前缀和 partial_sum
class Solution {
 public:
  Solution(std::vector<int> &w) : m_partial_sum_of_w(w.size()) {
	std::partial_sum(w.begin(), w.end(), m_partial_sum_of_w.begin());
  }

  int pickIndex() {
	int rd = rand()%(m_partial_sum_of_w.back()) + 1;	// 这里不能写成	int rd = rand()%(m_partial_sum_of_w.back() + 1);
														// 因为第一个元素的概率会变大
	return std::lower_bound(m_partial_sum_of_w.begin(), m_partial_sum_of_w.end(), rd)
		- m_partial_sum_of_w.begin();
  }
 private:
  std::vector<int> m_partial_sum_of_w;
};