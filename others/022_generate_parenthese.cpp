//
// Created by lp on 2023/2/7.
//
#include "vector"
#include "string"

// 动态规划
std::vector<std::string> generateParenthesis(int n) {
  if (n==0) return {};
  if (n==1) return {"()"};

  std::vector<std::vector<std::string>> res(n + 1);
  res[0].push_back("");
  res[1].push_back("()");
  for (int i = 2; i <= n; ++i) {
	for (int j = 0; j < i; ++j) {
	  for (const auto &p : res[j]) {
		for (const auto &q : res[i - 1 - j]) {
		  res[i].push_back("(" + p + ")" + q);
		}
	  }
	}
  }
  return res[n];
}

void generateParenthesis_dfs_aux(int num_left, int num_right, std::string s, std::vector<std::string> &res) {
  if ((num_left | num_right)==0) {
	res.push_back(s);
	return;
  }

  if (num_left==num_right) {
	generateParenthesis_dfs_aux(num_left - 1, num_right, s + "(", res);
	return;
  }

  if (num_left==0) {
	generateParenthesis_dfs_aux(num_left, num_right - 1, s + ")", res);
  } else {
	generateParenthesis_dfs_aux(num_left - 1, num_right, s + "(", res);
	generateParenthesis_dfs_aux(num_left, num_right - 1, s + ")", res);
  }
}

std::vector<std::string> generateParenthesis_dfs(int n) {
  if (n==0) return {};
  if (n==1) return {"()"};
  std::vector<std::string> res;
  generateParenthesis_dfs_aux(n, n, "", res);
  return res;
}