//
// Created by lp on 2022/10/2.
//
#include "vector"

// 回溯
// 对于每一个当前位置 i，我们可以将其于之后的任意位置交换，
// 因为位置 i 的数可以是位置 i 以及其后的数，
// 然后继续处理位置 i + 1，直到处理到最后一位。
void recall(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int level) {
  // level 表示当前是处于哪个位置
  if (level==nums.size() - 1) {
	ans.push_back(nums);
	return;
  }

  for (int i = level; i < nums.size(); ++i) {
	std::swap(nums[level], nums[i]);    // 与位置 i 后面的数（包括）进行交换
	recall(nums, ans, level + 1);
	std::swap(nums[level], nums[i]);    // 与位置 i 后面的数（包括）交换回来
  }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums) {
  if (nums.size()==1)return {{nums[0]}};
  std::vector<std::vector<int>> ans;
  recall(nums, ans, 0);
  return ans;
}