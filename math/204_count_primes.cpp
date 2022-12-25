//
// Created by lp on 2022/11/4.
//
#include "vector"

// 从 2 到 n 遍历，假设当前遍历到 m，则把所有小于等于 n 的、且是 m 的倍
// 数的整数标为和数；遍历完成后，没有被标为和数的数字即为质数。
int countPrimes(int n) {
  if (n <= 2) return 0;

  std::vector<bool> is_primes(n, true);
  int count = 0;
  for (int i = 2; i < n; ++i) {
	// 只有质数时才遍历，因为对于和数 m，会存在比 m 小的 a 和 b，使得a*b=m，那么在遍历 a 或者 b 时就已经设置了 m
	if (is_primes[i]) {
	  ++count;
	  for (int j = 2*i; j < n; j += i) {
		is_primes[j] = false;
	  }
	}
  }

  return count;
}