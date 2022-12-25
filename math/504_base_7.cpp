//
// Created by lp on 2022/11/4.
//
#include "string"

std::string convertToBase7(int num) {
  if (num < 7 && num >= 0) return std::to_string(num);
  if (num > -7 && num < 0) return "-" + std::to_string(-num);

  bool positive = num >= 0;
  num = abs(num);
  std::string res;
  int a;
  while (num >= 7) {
	a = num%7;
	num = num/7;
	res = std::to_string(a) + res;
  }
  if (num > 0) res = std::to_string(num) + res;
  if (!positive) res = "-" + res;

  return res;
}