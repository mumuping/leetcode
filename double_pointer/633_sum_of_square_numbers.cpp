//
// Created by lp on 2022/9/21.
//

#include "cmath"

bool judgeSquareSum(int c) {
  int left = 0, right = sqrt(c);

  int remain = 0;
  int right_square = 0;
  while (left <= right) {
	remain = c - left*left;
	right_square = right*right;
	if (remain==right_square)return true;
	else if (remain < right_square)--right;
	else ++left;
  }
  return false;
}