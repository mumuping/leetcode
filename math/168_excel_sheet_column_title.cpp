//
// Created by lp on 2022/11/6.
//
#include "string"
#include "algorithm"

std::string convertToTitle(int columnNumber) {
  std::string res;
  int remain = 0;
  while (columnNumber!=0) {
	--columnNumber;
	remain = columnNumber%26;
//	res.insert(res.begin(),'A'+remain);
	res += 'A' + remain;
	columnNumber /= 26;
  }
  std::reverse(res.begin(),res.end());

  return res;
}