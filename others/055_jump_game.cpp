//
// Created by lp on 2023/2/20.
//
#include "vector"

bool canJump(std::vector<int> &nums) {
  if (nums.empty()) return true;
  int n = nums.size();
  if (n==1) return true;

  bool res = true;
  int next_point = 0, end = nums[0];
  for (int i = 0; i < n - 1; ++i) {
	next_point = i + std::max(next_point, i + nums[i]);
	if (i==end) {
	  if (next_point >= n - 1) break;
	  else if (next_point==end) {
		res = false;
		break;
	  } else {
		end = next_point;
		next_point = 0;
	  }
	}
  }
  return res;
}

bool canJump_(std::vector<int> &nums) {
  if (nums.empty()) return true;
  int n = nums.size();
  if (n==1) return true;

  int max_distance = 0;
  for (int i = 0; i < n - 1; ++i) {
	max_distance = std::max(max_distance, i + nums[i]);
	if (i>=max_distance) return false;
  }
  return true;
}