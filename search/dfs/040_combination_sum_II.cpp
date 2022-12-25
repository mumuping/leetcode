//
// Created by lp on 2022/10/14.
//
#include "vector"
#include "algorithm"

void dfs(std::vector<std::vector<int>> &ans,
		 const std::vector<int> &candidates,
		 std::vector<int> &combination,
		 int level,
		 int target) {

  for(int i=level;i<candidates.size();++i){
	if(i!=level&&candidates[i]==candidates[i-1]) continue;
	if(target<candidates[i]) return;
	else if(candidates[i]<target){
	  combination.push_back(candidates[i]);
	  dfs(ans,candidates,combination,i+1,target-candidates[i]);
	  combination.pop_back();
	}
	else{
	  combination.push_back(candidates[i]);
	  ans.push_back(combination);
	  combination.pop_back();
	}
  }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
  int size_candidates = candidates.size();
  if (size_candidates==1) {
	if (candidates[0]==target) return {{target}};
	else return {};
  }

  // 先对 candidates 进行排序
  std::sort(candidates.begin(),candidates.end());

  // 利用深度优先搜索
  std::vector<std::vector<int>> ans;
  std::vector<int> combination;
  dfs(ans,candidates,combination,0,target);

  return ans;
}