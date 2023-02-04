//
// Created by lp on 2023/2/4.
//
#include "climits"

int reverse(int x) {
  int res = 0;
  int remainder;
  const int INTMAX30 = INT_MAX/10, INTMIN30 = INT_MIN/10;
  while (x!=0) {
	remainder = x%10;
	if (res > INTMAX30 || res < INTMIN30) return 0;
	res = res*10 + remainder;
	x /= 10;
  }
  return res;
}