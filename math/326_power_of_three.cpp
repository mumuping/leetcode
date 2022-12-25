//
// Created by lp on 2022/11/5.
//
#include "cmath"

bool isPowerOfThree(int n) {
  if (n==0 || n==2) return false;
  if (n==1 || n==3) return true;

  while (n%3==0) {
	n /= 3;
	if (n==3) return true;
  }

  return false;
}

// 利用对数
bool isPowerOfThree_log(int n) {
  return fmod(log10(n)/log10(3), 1)==0;
}

// int 范围内 3 的最大次方是 3^19=1162261467
bool isPowerOfThree_max(int n) {
  return n > 0 && 1162261467%n==0;
}