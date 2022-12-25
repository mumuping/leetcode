//
// Created by lp on 2022/11/19.
//
#include "unordered_set"
#include "vector"

int longestConsecutive(std::vector<int> &nums) {
  int n = nums.size();
  if (n <= 1) return n;

  std::unordered_set<int> s(n);
  for (int i = 0; i < n; ++i) {
	s.emplace(nums[i]);
  }

  int longest = 0, tmp = 0;
  int entry = 0, check = 0;
  while (!s.empty()) {
	entry = *s.begin();
	tmp = 1;
	s.erase(entry);

	// 检查前面
	check = entry - 1;
	while (s.find(check)!=s.end()) {
	  ++tmp;
	  --check;
	}
	// 检查后面
	check = entry + 1;
	while (s.find(check)!=s.end()) {
	  ++tmp;
	  ++check;
	}

	longest = std::max(longest, tmp);
  }

  return longest;
}