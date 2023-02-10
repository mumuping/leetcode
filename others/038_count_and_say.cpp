//
// Created by 18315 on 2023/2/10.
//
#include "string"
#include "algorithm"

std::string int2str(int n) {
  if (n == 0) return "0";
  std::string s;
  while (n != 0) {
    s.push_back('0' + n % 10);
    n /= 10;
  }
  std::reverse(s.begin(), s.end());
  return s;
}

std::string countAndSay(int n) {
  if (n == 1) return "1";
  if (n == 2) return "11";
  if (n == 3) return "21";

  std::string s = "21", tmp;
  for (int i = 4; i <= n; ++i) {
    char value = s[0];
    int count = 1, index = 1;
    while (index < s.length()) {
      if (s[index] == value) ++count;
      else {
        tmp += int2str(count);
        tmp += value;
        count = 1;
        value = s[index];
      }
      ++index;
    }
    tmp += int2str(count);
    tmp += value;
    s = tmp;
    tmp.clear();
  }

  return s;
}