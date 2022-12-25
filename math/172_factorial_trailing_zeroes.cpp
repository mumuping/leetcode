//
// Created by lp on 2022/11/4.
//

// 任意一个正整数都可以分解成质数的乘积
// 那么这道题可以将 n! 的每个元素都分解成质数的乘积
// 2*5 构成 0 结尾，因此只需要计算有多少个 0 5 对即可，
// 又可证明 5 的个数要小于 2 的个数，因此只需要计算 5 的个数即可
// 即可求 [5,n] 中每个数的 5 的个数
int trailingZeroes(int n) {
  if (n < 5) return 0;
  int ans = 0;

  int cur;
  for (int i = 5; i <= n; ++i) {
	cur = i;
	while (cur%5==0) {
	  ++ans;
	  cur /= 5;
	}
  }

  return ans;
}

int trailingZeroes_(int n) {
  int ans = 0;

  while (n > 0) {
	ans += n/5;
	n /= 5;
  }

  return ans;
}