//
// Created by lp on 2022/11/9.
//
int hammingDistance(int x, int y) {
  int diff = x ^ y;

  int distance = 0;
  while (diff!=0) {
	if (diff%2) {
	  ++distance;
	}
	diff /= 2;
  }

  return distance;
}

// 使用位运算更快
int hammingDistance_bit(int x, int y) {
  int diff = x ^ y;
  int distance = 0;

  while (diff) {
	distance += diff & 1;
	diff >>= 1;
  }

  return distance;
}

// 或者使用内置的计算二进制中 1 的个数
int hammingDistance_builtin(int x, int y) {
  return __builtin_popcount(x ^ y);
}

// 还可以使用 x&(x-1) 来快速得到 1 的个数，跳过两个 1 之间的 0
int hammingDistance_x(int x, int y) {
  int diff = x ^ y, distance = 0;
  while (diff) {
	diff &= (diff - 1);
	++distance;
  }

  return distance;
}