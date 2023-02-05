//
// Created by lp on 2023/2/5.
//
#include "string"

inline int symbol_to_value(char symbol) {
  switch (symbol) {
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	case 'a': return 4;
	case 'b': return 9;
	case 'c': return 40;
	case 'd': return 90;
	case 'e': return 400;
	case 'f': return 900;
  }
  return 0;
}

int romanToInt(std::string s) {
  if (s.empty()) return 0;
  int n = s.size(), num = 0;

  int pre_value = symbol_to_value(s[0]);
  if (n==1) return pre_value;
  for (int i = 1; i < n; ++i) {
	if (pre_value < symbol_to_value(s[i])) {
	  num -= pre_value;
	} else {
	  num += pre_value;
	}
	pre_value = symbol_to_value(s[i]);
  }
  num += pre_value;
  return num;
}