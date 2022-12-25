//
// Created by lp on 2022/11/9.
//
#include "cstdint"

uint32_t reverseBits(uint32_t n) {
  int res = 0, count = 31;
  while (n!=0) {
	if (n & 1) {
	  res += 1 << count;
	}
	--count;
	n >>= 1;
  }

  return res;
}

// 32 次循环
uint32_t reverseBits_(uint32_t n) {
  uint32_t res = 0;

  for (int i = 0; i < 32; ++i) {
	res <<= 1;
	res += n & 1;
	n >>= 1;
  }

  return res;
}

// 这道题还可以使用分治法
// 若要翻转一个二进制串，可以将其均分成左右两部分，对每部分递归执行翻转操作，
// 然后将左半部分拼在右半部分的后面，即完成了翻转。
uint32_t reverseBits_dichotomy(uint32_t n) {
  const uint32_t M1 = 0x55555555; // 01010101010101010101010101010101
  const uint32_t M2 = 0x33333333; // 00110011001100110011001100110011
  const uint32_t M4 = 0x0f0f0f0f; // 00001111000011110000111100001111
  const uint32_t M8 = 0x00ff00ff; // 00000000111111110000000011111111

  n = n >> 1 & M1 | (n & M1) << 1;
  n = n >> 2 & M2 | (n & M2) << 2;
  n = n >> 4 & M4 | (n & M4) << 4;
  n = n >> 8 & M8 | (n & M8) << 8;

  return n >> 16 | n << 16;
}