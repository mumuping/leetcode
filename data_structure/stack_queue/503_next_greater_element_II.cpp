//
// Created by lp on 2022/11/24.
//
#include "vector"
#include "stack"

std::vector<int> nextGreaterElements(std::vector<int> &nums) {
  int n = nums.size();
  if (n==0) return {};
  if (n==1) return {-1};

  std::stack<int> s;
  std::vector<int> res(n);
  for (int i = 0; i < n; ++i) {
	while (!s.empty() && nums[s.top()] < nums[i]) {
	  res[s.top()] = nums[i];
	  s.pop();
	}
	s.push(i);
  }

  // 处理 stack 中剩下的
  if (s.size()==1) res[s.top()] = -1;
  else {
	int i = 0;
	while (i < n) {
	  if (nums[s.top()] < nums[i]) {
		res[s.top()] = nums[i];
		s.pop();
		continue;
	  }
	  ++i;
	}

	while (!s.empty()) {
	  res[s.top()] = -1;
	  s.pop();
	}
  }

  return res;
}

// 遍历一遍式不够的，因此把前 n−1 个元素拼接在原序列的后面
std::vector<int> nextGreaterElements_(std::vector<int> &nums) {
  int n = nums.size();
  if (n==0) return {};
  if (n==1) return {-1};

  std::stack<int> s;
  std::vector<int> res(n, -1);
  for (int i = 0; i < 2*n - 1; ++i) {
	while (!s.empty() && nums[s.top()] < nums[i%n]) {
	  res[s.top()] = nums[i%n];
	  s.pop();
	}
	s.push(i%n);
  }

  return res;
}