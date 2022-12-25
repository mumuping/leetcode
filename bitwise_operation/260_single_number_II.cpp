//
// Created by lp on 2022/11/12.
//
#include "vector"
#include "climits"

std::vector<int> singleNumber(std::vector<int> &nums) {
  int size = nums.size();
  if (size==2) return {nums[0], nums[1]};

  // 得到两个数的异或值
  // 注意这里 a 可能会超界，因此使用 long
  // long a = 0;
  int a = 0;
  for (int i = 0; i < size; ++i) {
	a ^= nums[i];
  }

  // 取出异或值中最低位的 1，显然该位一个为 1，一个为 0
  // long lowest_of_a = a & (-a);
  int lowest_of_a = (a==INT_MIN) ? INT_MIN : a & (-a);    // 防止超界

  // 按照异或值中最低位的 1 将 nums 中的数分为左右两部分，分别进行异或即可得到两数
  int number1 = 0, number2 = 0;
  for (int i = 0; i < size; ++i) {
	if (nums[i] & lowest_of_a)
	  number1 ^= nums[i];
	else number2 ^= nums[i];
  }

  return {number1, number2};
}