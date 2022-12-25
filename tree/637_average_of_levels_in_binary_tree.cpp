//
// Created by lp on 2022/12/16.
//
#include "vector"
#include "queue"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<double> averageOfLevels(TreeNode *root) {
  if (!root) return {};
  std::vector<double> averages;
  std::queue<TreeNode *> q;
  q.push(root);

  double sum;
  int n;
  while (!q.empty()) {
	sum = 0;
	n = q.size();
	for (int i = 0; i < n; ++i) {
	  sum += q.front()->val;
	  if (q.front()->left) q.push(q.front()->left);
	  if (q.front()->right) q.push(q.front()->right);
	  q.pop();
	}
	averages.push_back(sum/n);
  }

  return averages;
}