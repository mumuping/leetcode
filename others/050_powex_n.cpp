//
// Created by lp on 2023/2/18.
//
#include "climits"

double myPow(double x, int n) {
  if (x==1 || (n==0 && x!=0)) return 1;
  if (x==0 && n <= 0) return 0;
  if (x==-1) return n%2==0 ? 1 : -1;

  bool is_int_min = false;
  if (n < 0) {
	x = 1/x;
	if (n==INT_MIN) {
	  n = INT_MAX;
	  is_int_min = true;
	} else n = -n;
  }
  double res = 1, cur = x;
  while (n!=0) {
	if (n & 1) res *= cur;
	cur = cur*cur;
	n >>= 1;
  }
  return is_int_min ? res*x : res;
}