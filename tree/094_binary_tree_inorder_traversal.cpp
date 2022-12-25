//
// Created by lp on 2022/12/21.
//
#include "vector"
#include "stack"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> inorderTraversal_stack(TreeNode *root) {
  if (!root) return {};
  std::stack<TreeNode *> s;
  std::vector<int> ans;
  TreeNode *node = root;

  while (!s.empty() || node) {
	while (node) {
	  s.push(node);
	  node = node->left;
	}
	node = s.top();
	ans.push_back(node->val);
	s.pop();
	node = node->right;
  }
  return ans;
}

void inorderTraversal_aux(TreeNode *node, std::vector<int> &ans) {
  if (!node) return;

  inorderTraversal_aux(node->left, ans);
  ans.push_back(node->val);
  inorderTraversal_aux(node->right, ans);
}

std::vector<int> inorderTraversal(TreeNode *root) {
  std::vector<int> ans;
  inorderTraversal_aux(root, ans);
  return ans;
}