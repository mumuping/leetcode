//
// Created by lp on 2022/12/6.
//
#include "string"
#include "vector"
#include "numeric"

class Solution {
 public:
  int calculate(std::string s) {
	std::vector<int> stk;
	char preSign = '+';
	int num = 0;
	int n = s.length();
	for (int i = 0; i < n; ++i) {
	  if (isdigit(s[i])) {
		num = num * 10 + int(s[i] - '0');
	  }
	  if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
		switch (preSign) {
		  case '+':
			stk.push_back(num);
			break;
		  case '-':
			stk.push_back(-num);
			break;
		  case '*':
			stk.back() *= num;
			break;
		  default:
			stk.back() /= num;
		}
		preSign = s[i];
		num = 0;
	  }
	}
	return std::accumulate(stk.begin(), stk.end(), 0);
  }
};
