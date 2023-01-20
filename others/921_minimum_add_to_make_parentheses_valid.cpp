//
// Created by 18315 on 2023/1/20.
//
#include "string"
#include "stack"

int minAddToMakeValid(std::string s) {
  int n = s.size();
  if (n <= 1) return n;
  int mini = 0, left = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') ++left;
    else --left;
    if (left == -1) {
      left = 0;
      ++mini;
    }
  }
  return mini + left;
}

int minAddToMakeValid_stack(std::string s) {
  int n = s.size();
  if (n <= 1) return n;
  int mini = 0;
  std::stack<char> sk;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') sk.push('(');
    else {
      if (sk.empty()) ++mini;
      else sk.pop();
    }
  }
  return mini + sk.size();
}
