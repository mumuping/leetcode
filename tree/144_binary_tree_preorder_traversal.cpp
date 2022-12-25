//
// Created by lp on 2022/12/16.
//
#include "stack"
#include "vector"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> preorderTraversal(TreeNode *root) {
  if (!root) return {};

  std::stack<TreeNode *> s;
  std::vector<int> res;
  s.push(root);
  TreeNode *node = nullptr;
  while (!s.empty()) {
	node = s.top();
	res.push_back(node->val);
	s.pop();
	if (node->right) s.push(node->right);
	if (node->left) s.push(node->left);
  }

  return res;
}