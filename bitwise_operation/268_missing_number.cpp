//
// Created by lp on 2022/11/12.
//
#include "vector"
#include "numeric"

int missingNumber(std::vector<int> &nums) {
  int n = nums.size();
  int sum = std::accumulate(nums.begin(), nums.end(), 0);

  return n*(n + 1)/2 - sum;
}

// 也可以使用 bits
// 在 nums 后面加 [0,n] 的数，然后异或
int missingNumber_bits(std::vector<int> &nums) {
  int size = nums.size();
  if (size==0) return -1;

  int bits_xor = nums[0];
  for (int i = 1; i < size; ++i) {
	bits_xor ^= nums[i];
  }
  for (int i = 0; i <= size; ++i) {
	bits_xor ^= i;
  }

  return bits_xor;
}