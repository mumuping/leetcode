//
// Created by lp on 2022/12/24.
//
#include "unordered_set"
#include "vector"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *node, int k, std::unordered_set<int> &set) {
  if (!node) return false;
  if (set.count(k - node->val) > 0) return true;
  set.insert(node->val);
  return dfs(node->left, k, set) || dfs(node->right, k, set);
}

bool findTarget_dfs(TreeNode *root, int k) {
  std::unordered_set<int> set;
  return dfs(root, k, set);
}

void build_vector(TreeNode *node, std::vector<int> &vt) {
  if (!node) return;
  build_vector(node->left, vt);
  vt.push_back(node->val);
  build_vector(node->right, vt);
}

bool findTarget_vector(TreeNode *root, int k) {
  std::vector<int> vt;
  build_vector(root, vt);
  int i = 0, j = vt.size() - 1;
  while (i < j) {
	int val = vt[i] + vt[j];
	if (val==k) return true;
	else if (val < k) ++i;
	else --j;
  }
  return false;
}