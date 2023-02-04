//
// Created by lp on 2023/2/4.
//
#include "string"

std::string convert(std::string s, int numRows) {
  if (numRows==1) return s;
  int length_s = s.size(), length_group = numRows*2 - 2, nums_groups = (s.size() + length_group - 1)/length_group;
  std::string res;
  for (int i = 0; i < length_s; i += length_group)
	res += s[i];
  for (int i = 1; i < numRows - 1; ++i) {
	int j = i, k = length_group - i*2;
	while (j < length_s) {
	  res += s[j];
	  if (k + j < length_s) res += s[k + j];
	  j += length_group;
	}
  }
  for (int i = numRows - 1; i < length_s; i += length_group)
	res += s[i];

  return res;
}