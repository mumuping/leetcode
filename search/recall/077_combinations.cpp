//
// Created by lp on 2022/10/5.
//
#include "vector"

// 回溯
void recall(std::vector<std::vector<int>> &ans, std::vector<int> &comb, int n, int &k, int pos) {
  if (k==0) {
	ans.push_back(comb);
	return;
  }

  for (int i = pos; i <= n; ++i) {
	comb.push_back(i);
	--k;
	recall(ans, comb, n, k, i + 1);
	++k;
	comb.pop_back();
  }
}

std::vector<std::vector<int>> combine(int n, int k) {
  if (n==1) return {{1}};

  std::vector<std::vector<int>> ans;
  std::vector<int> comb;

  recall(ans, comb, n, k, 1);
  return ans;
}
