//
// Created by lp on 2022/10/31.
//
#include "vector"
#include "string"

// 以运算符为界限，分为左右两部分，分别进行计算
std::vector<int> divide_conquer(const std::string expression) {
  std::vector<int> ways;

  char op;
  for (int i = 0; i < expression.size(); ++i) {
	op = expression[i];
	if (op=='*' || op=='+' || op=='-') {    // 找到该表达式中的每一个运算符，然后分成左右两部分分别进行处理
	  std::vector<int> left = divide_conquer(expression.substr(0, i));
	  std::vector<int> right = divide_conquer(expression.substr(i + 1));
	  for (auto &l : left) {
		for (auto &r : right) {
		  switch (op) {
			case '*': ways.emplace_back(l*r);
			  break;
			case '+':ways.emplace_back(l + r);
			  break;
			case '-':ways.emplace_back(l - r);
			  break;
		  }
		}
	  }
	}
  }
  // 如果没找到运算符，说明表达式只有一个数字
  if (ways.empty())ways.emplace_back(std::stoi(expression));

  return ways;
}

std::vector<int> diffWaysToCompute(std::string expression) {
  return divide_conquer(expression);
}

// 上面很明显会出现重复计算，因此可以从低向上采用动态规划
std::vector<int> diffWaysToCompute_dp(std::string expression) {
  // 先把数字和符号分别单独拿出来
  int size = expression.size();
  if (size==0) return {};
  if (size==1) return {stoi(expression)};
  std::vector<int> numbers, ops;

  size_t index = 0, index_sub = 0;
  while (true) {
	std::string sub = expression.substr(index);
	numbers.emplace_back(stoi(sub, &index_sub));
	if (index_sub!=sub.size()) {
	  switch (sub[index_sub]) {
		case '+': ops.emplace_back(0);
		  break;
		case '-': ops.emplace_back(1);
		  break;
		case '*': ops.emplace_back(2);
		  break;
	  }
	  index += index_sub + 1;
	} else {
	  break;
	}
  }

  // dp
  int n = numbers.size();
  std::vector<std::vector<std::vector<int>>> dp(n,
												std::vector<std::vector<int>>(n,
																			  std::vector<int>()));
  for (int i = 0; i < n; ++i) {   // 初始化
	dp[i][i].emplace_back(numbers[i]);
  }
  int tmp;
  for (int i = 1; i < n; ++i) {
	for (int j = 0; j + i < n; ++j) {
	  for (int k = j; k < j + i; ++k) {
		for (auto &left : dp[j][k]) {
		  for (auto &right : dp[k + 1][j + i]) {
			switch (ops[k]) {
			  case 0: tmp = left + right;
				break;
			  case 1: tmp = left - right;
				break;
			  case 2: tmp = left*right;
				break;
			}
			dp[j][j + i].emplace_back(tmp);
		  }
		}
	  }
	}
  }
  return dp[0][n - 1];
}