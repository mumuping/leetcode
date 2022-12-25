//
// Created by lp on 2022/12/6.
//
#include "string"

int countBinarySubstrings(std::string s) {
  int n = s.size();
  if (n <= 1) return 0;

  int pre = 1, cur = 1;
  int count = 0;
  for (int i = 1; i < n; ++i) {
	if (s[i]==s[i - 1]) {
	  ++cur;
	} else {
	  pre = cur;
	  cur = 1;
	}

	if (pre >= cur) ++count;
  }

  return count;
}

int countBinarySubstrings_(std::string s) {
  int n = s.size();
  if (n <= 1) return 0;

  int left, right;
  int left_val, right_val;
  int count = 0;
  for (int i = 1; i < n; ++i) {
	left = i - 1;
	left_val = s[left];
	right = i;
	right_val = s[right];

	if (left_val!=right_val) {
	  while (left >= 0 && right < n && s[left]==left_val && s[right]==right_val) {
		++count;
		--left;
		++right;
	  }
	}
  }

  return count;
}