//
// Created by lp on 2022/10/1.
//
#include "vector"

void sortColors(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums==1)return;

  int left = 0, right = size_nums - 1;
  // 先将所有的 2 放置在末尾
  while (left < right) {
	// 将 right 左移至指向的不等于 2
	// 注意这里每次都要判断 left<right 是否成立
	// 因为很可能出现超界的情况
	while (left < right && nums[right]==2)--right;
	// 将 left 右移至指向的等于 2
	while (left < right && nums[left]!=2)++left;
	if (left < right)
	  std::swap(nums[left], nums[right]);
  }

  // 再将所有的 1 放置在末尾
  left = 0;
  while (left < right) {
	while (left < right && nums[right]==1)--right;
	while (left < right && nums[left]!=1)++left;
	if (left < right)
	  std::swap(nums[left], nums[right]);
  }
  return;
}

// 最直接的方法是统计各字符出现的次数
void sortColors_(std::vector<int> &nums) {
  int size_nums = nums.size();

  // 用数组保存 1、2、3 各自出现的次数 hhhh
  int count[3] = {0};
  int i = 0;
  for (; i < size_nums; ++i)
	++count[nums[i]];

  // 返回结果
  i = 0;
  for (int number = 0; number < 3; ++number)
	for (int j = 0; j < count[number]; ++j)
	  nums[i++] = number;

  return;
}

// 使用单指针
void sortColor__(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums==1)return;

  int point_to_exchange = 0;
  // 先将所有的 0 放置在头部，再将所有的 1 放置在 0 的后面
  int index = 0;
  for (; index < size_nums; ++index) {
	if (nums[index]==0) {
	  std::swap(nums[point_to_exchange], nums[index]);
	  ++point_to_exchange;
	}
  }

  for (index = point_to_exchange; index < size_nums; ++index) {
	if (nums[index]==1) {
	  std::swap(nums[point_to_exchange], nums[index]);
	  ++point_to_exchange;
	}
  }
  return;
}