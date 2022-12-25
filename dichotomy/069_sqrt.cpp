//
// Created by lp on 2022/9/26.
//
#include "cmath"

// 二分法
int mySqrt(int x) {
  if (x==0 || x==1)return x;

  int left = 0, right = x;
  int mid = 0;
  typedef long long ll;
  ll power_of_mid;
  while (left + 1 < right) {
	mid = (left + right)/2;
	power_of_mid = (ll)mid*mid;
	if (power_of_mid==x)return mid;
	else if (power_of_mid < x)left = mid;
	else right = mid;
  }
  return left;
}

// 牛顿迭代法
int mySqrt_Newton(int x) {
  if (x==0 || x==1) return x;

  double ans = x - 1;
  double last_ans = ans;
  while (true) {
	last_ans = ans;
	ans = (ans + x/ans)/2;
	if (fabs(last_ans - ans) <= 1e-7)break;
  }
  return (int)ans;
}