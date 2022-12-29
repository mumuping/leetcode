//
// Created by lp on 2022/12/29.
//
#include "vector"
#include "climits"

int dfs_highestScore(const std::vector<std::vector<int>> &children,
					 long long &highest_score,
					 int node,
					 int &highest_count) {
  long long score;
  if (children[node].empty()) {
	score = children.size() - 1;
	if (score > highest_score) {
	  highest_score = score;
	  highest_count = 1;
	} else if (score==highest_score) {
	  ++highest_count;
	}
	return 1;
  }

  int child1 = dfs_highestScore(children, highest_score, children[node][0], highest_count);
  int child2 = 0;
  if (children[node].size() > 1)
	child2 = dfs_highestScore(children, highest_score, children[node][1], highest_count);
  int cur_count = child1 + child2 + 1;
  int remain = children.size() - cur_count;
  if (child2==0) child2 = 1;
  if (remain==0) remain = 1;
  score = (long long)child1*child2*remain;
  if (score > highest_score) {
	highest_score = score;
	highest_count = 1;
  } else if (score==highest_score) {
	++highest_count;
  }
  return cur_count;
}

int countHighestScoreNodes(std::vector<int> &parents) {
  int n = parents.size();
  if (n <= 1) return 0;
  std::vector<std::vector<int>> children(n, std::vector<int>());
  for (int i = 1; i < n; ++i) {
	children[parents[i]].push_back(i);
  }

  long long highest_score = INT_MIN;
  int count = 0;
  dfs_highestScore(children, highest_score, 0, count);
  return count;
}