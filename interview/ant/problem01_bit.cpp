//
// Created by lp on 2023/4/6.
//
#include <iostream>

using ull = unsigned long long;
ull GetResultByBinary(int num, int k) {
  ull result = 0, tmp = 1;
  while (num) {
	if (num & 1) {
	  result += tmp;
	}
	num >>= 1;
	tmp *= k;
  }
  return result;
}

int FindBinary(int k, int target, bool left_boundary) {
  int left = 1, right = 1;
  ull tmp = 1;
  /* Get the binary number that can be converted to the result that is greater than the target */
  while (tmp < target) {
	right <<= 1;
	tmp *= k;
  }
  /* If target is left boundary, get the smallest number greater than target */
  if (left_boundary) {
	while (left < right) {
	  int mid = left + (right - left)/2;
	  ull result = GetResultByBinary(mid, k);
	  if (result >= target) {
		right = mid;
	  } else {
		left = mid + 1;
	  }
	}
	return right;
  } else {
	/* If target is right boundary, get the largest number less than target */
	while (left < right) {
	  int mid = left + (right - left + 1)/2;
	  ull result = GetResultByBinary(mid, k);
	  if (result <= target) {
		left = mid;
	  } else {
		right = mid - 1;
	  }
	}
	return left;
  }
}

void Solve() {
  int q, l, r, k;
  std::cin >> q;
  while (q > 0) {
	--q;
	std::cin >> l >> r >> k;

	int left_num = FindBinary(k, l, true);
	int right_num = FindBinary(k, r, false);
	if (right_num < left_num) {
	  std::cout << 0 << std::endl;
	} else {
	  std::cout << right_num - left_num + 1 << std::endl;
	}
  }
}
