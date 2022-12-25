//
// Created by lp on 2022/11/4.
//

// 最大公因数
// 辗转相除法
int gcd(int a, int b) {
  if (b==0) return -1;

  int c;
  while ((c = a%b)!=0) {
	a = b;
	b = c;
  }

  return b;
}

// 最小公倍数
// 两数的乘积除以最大公倍数
int lcm(int a, int b) {
  return a*b/gcd(a, b);
}

// 扩展欧几里得算法
int xGCD(int a, int b, int &x, int &y) {
  if (b==0) {
	x = 1;
	y = 0;
	return a;
  }

  int x1, y1, gcd = xGCD(b, a%b, x1, y1);
  x = y1, y = x1 - (a/b)*y1;
  return gcd;
}