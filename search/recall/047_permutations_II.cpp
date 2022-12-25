//
// Created by lp on 2022/10/13.
//
#include "vector"
#include "unordered_set"

// 回溯法
// 对于一个存在重复值的数组，可以用一个 set 来保存已经交换过的值，
// 如果下一个待交换的值已经存在于 set 中，那么就应该跳过
// 当然也可以使用一个标记数组用来标记该元素是否已经交换过了
void recall(std::vector<int> &nums, std::vector<std::vector<int>> &ans,
			int level) {
  // 如果 level 是 nums 的最后一个，则将结果放入 ans 中
  if (level==nums.size() - 1) {
	ans.push_back(nums);
	return;
  }

  std::unordered_set<int> swaped; // 用于记录已经交换过的值
  for (int i = level; i < nums.size(); ++i) {
	if (swaped.count(nums[i])==0) {
	  swaped.emplace(nums[i]);
	  std::swap(nums[i], nums[level]);
	  recall(nums, ans, level + 1);
	  std::swap(nums[i], nums[level]);
	}
  }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
  if (nums.size()==1)
	return {{nums[0]}};
  std::vector<std::vector<int>> ans;
  recall(nums, ans, 0);
  return ans;
}