//
// Created by lp on 2022/11/5.
//
#include "string"
#include "algorithm"

std::string addStrings(std::string &num1, std::string &num2) {
  int size_num1 = num1.size(), size_num2 = num2.size();
  if (size_num1==0 || num1[0]=='0') return num2;
  if (size_num2==0 || num2[0]=='0') return num1;

  std::string res;
  int carry = 0, tmp;
  --size_num1;
  --size_num2;
  while (size_num1 >= 0 || size_num2 >= 0) {
	tmp = 0;
	if (size_num1 >= 0) {
	  tmp += num1[size_num1] - '0';
	  --size_num1;
	}
	if (size_num2 >= 0) {
	  tmp += num2[size_num2] - '0';
	  --size_num2;
	}
	tmp += carry;
	carry = tmp/10;
	tmp %= 10;
	res = std::to_string(tmp) + res;
  }
  if (carry!=0) res = std::to_string(carry) + res;

  return res;
}

// 当然也可以先反转字符串，相加，再反转
std::string addString_reverse(std::string &num1, std::string &num2) {
  int size_num1 = num1.size(), size_num2 = num2.size();
  if (size_num1==0 || num1[0]=='0') return num2;
  if (size_num2==0 || num2[0]=='0') return num1;

  std::reverse(num1.begin(), num1.end());
  std::reverse(num2.begin(), num2.end());

  std::string res("");
  int i = 0, j = 0;
  int carry = 0, tmp;

  while (i < size_num1 || j < size_num2) {
	tmp = carry;
	if (i < size_num1) {
	  tmp += num1[i] - '0';
	  ++i;
	}
	if (j < size_num2) {
	  tmp += num2[j] - '0';
	  ++j;
	}
	carry = tmp/10;
	tmp %= 10;
	res += tmp + '0';
  }
  if (carry!=0) res += carry + '0';
  std::reverse(res.begin(), res.end());

  return res;
}
