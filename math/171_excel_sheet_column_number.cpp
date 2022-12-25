//
// Created by lp on 2022/11/6.
//
#include "string"

int titleToNumber(std::string columnTitle) {
  int size = columnTitle.size();
  if (size==0) return 0;

  int val = 0;
  for (int i = 0; i < size; ++i) {
	val *= 26;
	val += columnTitle[i] - 'A' + 1;
  }

  return val;
}