//
// Created by lp on 2023/2/8.
//
#include "climits"

int divide(int dividend, int divisor) {
  bool is_negative = (dividend >> 31) ^ (divisor >> 31);
  // 一些特殊情况
  if (divisor==1) return dividend;
  if (divisor==-1) return dividend==INT_MIN ? INT_MAX : -dividend;
  if (divisor==INT_MIN) return dividend==INT_MIN ? 1 : 0;
  if (dividend==0) return 0;

  if (dividend > 0) dividend = -dividend;
  if (divisor < 0) divisor = -divisor;

  int divisor_tmp = divisor, times = 1;
  while ((-(dividend + divisor_tmp)) > divisor_tmp) {
	divisor_tmp <<= 1;
	times <<= 1;
  }

  int res = 0;
  while (dividend <= -divisor) {
	while (dividend > -divisor_tmp && divisor_tmp > divisor) {
	  divisor_tmp >>= 1;
	  times >>= 1;
	}
	dividend += divisor_tmp;
	res += times;
  }
  return is_negative ? -res : res;
}