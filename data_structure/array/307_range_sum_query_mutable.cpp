//
// Created by lp on 2022/11/30.
//
#include "vector"
#include "cmath"
#include "numeric"

class NumArray_segment_tree {
 public:
  NumArray_segment_tree(std::vector<int> &nums) : m_nums(nums), m_size(nums.size()), m_segment_tree(nums.size()*4) {
	build_tree(0, 0, m_size - 1);
  }

  void update(int index, int val) {
	update_tree(0, 0, m_size - 1, index, val);
  }

  int sumRange(int left, int right) {
	return range(0, 0, m_size - 1, left, right);
  }

 private:
  void build_tree(int node, int left, int right) {
	if (left==right) {
	  m_segment_tree[node] = m_nums[left];
	  return;
	}

	int mid = left + (right - left)/2;
	build_tree(2*node + 1, left, mid);
	build_tree(2*node + 2, mid + 1, right);
	m_segment_tree[node] = m_segment_tree[2*node + 1] + m_segment_tree[2*node + 2];
  }

  void update_tree(int node, int left, int right, int index, int val) {
	if (left==right) {
	  m_segment_tree[node] = val;
	  return;
	}

	int mid = left + (right - left)/2;
	if (index <= mid) {
	  update_tree(2*node + 1, left, mid, index, val);
	} else {
	  update_tree(2*node + 2, mid + 1, right, index, val);
	}
	m_segment_tree[node] = m_segment_tree[2*node + 1] + m_segment_tree[2*node + 2];
  }

  int range(int node, int left, int right, int range_begin, int range_end) {
	if (left==range_begin && right==range_end) {
	  return m_segment_tree[node];
	}

	int mid = left + (right - left)/2;
	if (range_end <= mid) {
	  return range(2*node + 1, left, mid, range_begin, range_end);
	} else if (range_begin > mid) {
	  return range(2*node + 2, mid + 1, right, range_begin, range_end);
	} else {
	  return range(2*node + 1, left, mid, range_begin, mid) +
		  range(2*node + 2, mid + 1, right, mid + 1, range_end);
	}
  }

 private:
  std::vector<int> m_nums;
  std::vector<int> m_segment_tree;
  int m_size;
};

// 分块
class NumArray_block {
 public:
  NumArray_block(std::vector<int> &nums) : m_nums(nums), size(sqrt(nums.size())) {
	const int n = m_nums.size();
	const int blocks = (n + size - 1)/size;
	m_blocks_sum.reserve(blocks);

	int start = 0, end = 0;
	for (int i = 0; i < blocks; ++i) {
	  start = end;
	  end += std::min(size, n - end);
	  m_blocks_sum[i] = std::accumulate(m_nums.begin() + start, m_nums.begin() + end, 0);
	}
  }

  void update(int index, int val) {
	const int i = index/size;
	m_blocks_sum[i] += val - m_nums[index];
	m_nums[index] = val;
  }

  int sumRange(int left, int right) {
	int left_index = left/size, right_index = right/size;
	if (left_index==right_index) return std::accumulate(m_nums.begin() + left, m_nums.begin() + right + 1, 0);

	int sum_of_left = std::accumulate(m_nums.begin() + left, m_nums.begin() + size*(left_index + 1), 0);
	int sum_of_right = std::accumulate(m_nums.begin() + size*right_index, m_nums.begin() + right + 1, 0);
	int sum_of_middle = std::accumulate(m_blocks_sum.begin() + left_index + 1, m_blocks_sum.begin() + right_index, 0);
	return sum_of_left + sum_of_middle + sum_of_right;
  }

 private:
  std::vector<int> m_nums;
  std::vector<int> m_blocks_sum;
  const int size;
};

// 暴力
class NumArray {
 public:
  NumArray(std::vector<int> &nums) : m_nums(nums) {}

  void update(int index, int val) {
	m_nums[index] = val;
  }

  int sumRange(int left, int right) {
	int res = 0;
	for (int i = left; i <= right; ++i)
	  res += m_nums[i];
	return res;
  }

 private:
  std::vector<int> m_nums;
};