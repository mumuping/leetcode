//
// Created by 18315 on 2023/1/19.
//
#include "string"
#include "algorithm"

std::string multiply(std::string num1, std::string num2) {
  int n1 = num1.size(), n2 = num2.size();
  std::reverse(num1.begin(), num1.end());
  std::reverse(num2.begin(), num2.end());
  std::string ans(n1 + n2, '0');

  int multi;
  for (int i = 0; i < n1; ++i) {
    for (int j = 0; j < n2; ++j) {
      multi = (num1[i] - '0') * (num2[j] - '0');
      multi += ans[i + j] - '0';
      ans[i + j] = (multi % 10) + '0';
      ans[i + j + 1] += multi / 10;
    }
  }

  int end = n1 + n2 - 1;
  while (end >= 0 && ans[end] == '0') {
    ans.pop_back();
    --end;
  }
  if (end < 0) ans.push_back('0');
  else std::reverse(ans.begin(), ans.end());

  return ans;
}