//
// Created by lp on 2023/2/22.
//
#include "string"

int lengthOfLastWord(std::string s) {
  if (s.empty()) return 0;
  int i = s.size() - 1, length = 0;
  while (i >= 0 && s[i]==' ') --i;
  if (i < 0) return 0;
  while (i >= 0 && s[i--]!=' ') ++length;
  return length;
}