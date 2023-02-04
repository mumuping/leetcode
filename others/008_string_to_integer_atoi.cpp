//
// Created by lp on 2023/2/4.
//
#include "string"
#include "climits"

int myAtoi(std::string s) {
  int n = s.size(), res = 0;
  int index = 0;
  while (index < n && s[index]==' ') ++index;
  if (index==n) return 0;

  bool is_positive = true;
  if (s[index]=='-') {
	is_positive = false;
	++index;
  } else if (s[index]=='+') {
	++index;
  }

  while (index < n && s[index]=='0') ++index;
  if (index==n || s[index] < '0' || s[index] > '9') return 0;
  if (!is_positive) {
	res = -(s[index] - '0');
	++index;
  }

  const int INTMAX30 = INT_MAX/10, INTMIN30 = INT_MIN/10;
  int next;
  while (index < n && s[index] >= '0' && s[index] <= '9') {
	next = s[index] - '0';
	if (is_positive) {
	  if (res > INTMAX30 || (res==INTMAX30 && next > 7)) return INT_MAX;
	  else res = res*10 + next;
	}
	if (!is_positive) {
	  if (res < INTMIN30 || (res==INTMIN30 && next > 8)) return INT_MIN;
	  else res = res*10 - next;
	}
	++index;
  }
  return res;
}