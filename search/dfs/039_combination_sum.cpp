//
// Created by lp on 2022/10/14.
//

#include "vector"
#include "algorithm"

// 深度优先 或者 叫回溯也可以
void dfs(std::vector<std::vector<int>> &ans,
		 const std::vector<int> &candidates,
		 std::vector<int> &combination,
		 int level,
		 int target) {
  for (int i = level; i < candidates.size(); ++i) {
	if (target < candidates[i]) return;
	else if (candidates[i] < target) {
	  combination.push_back(candidates[i]);
	  dfs(ans, candidates, combination, i, target - candidates[i]);
	  combination.pop_back();
	} else {
	  combination.push_back(candidates[i]);
	  ans.push_back(combination);
	  combination.pop_back();
	  return;
	}
  }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
  int size_candidates = candidates.size();
  if (size_candidates==1) {
	if (candidates[0]==target)return {{candidates[0]}};
	else return {};
  }

  // 先将 candidates 进行从小到大排序
  std::sort(candidates.begin(), candidates.end());
  // 再利用深度优先进行遍历
  std::vector<std::vector<int>> ans;
  std::vector<int> combination;

  dfs(ans,candidates,combination,0,target);
  return ans;
}