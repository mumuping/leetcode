//
// Created by lp on 2023/3/2.
//
#include "vector"

std::vector<int> plusOne(std::vector<int> &digits) {
  if (digits.empty()) return {};
  int n = digits.size();
  if (digits[0]==0) return {1};

  std::vector<int> res = digits;
  for (int i = n - 1; i >= 0; --i) {
	if (res[i]==9) {
	  res[i] = 0;
	} else {
	  ++res[i];
	  return res;
	}
  }
  res.insert(res.begin(), 1);
  return res;
}