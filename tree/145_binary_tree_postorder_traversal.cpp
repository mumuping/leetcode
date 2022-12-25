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

std::vector<int> postorderTraversal_stack(TreeNode *root) {
  if (!root) return {};
  std::stack<TreeNode *> s;
  std::vector<int> ans;
  TreeNode *node = root, *pre = nullptr;
  while (node || !s.empty()) {
	while (node) {
	  s.push(node);
	  node = node->left;
	}
	node = s.top();
	if (!node->right || node->right==pre) {
	  s.pop();
	  ans.push_back(node->val);
	  pre = node;
	  node = nullptr;
	} else {
	  node = node->right;
	}
  }
  return ans;
}

void postorderTraversal_aux(TreeNode *node, std::vector<int> &ans) {
  if (!node) return;

  postorderTraversal_aux(node->left, ans);
  postorderTraversal_aux(node->right, ans);
  ans.push_back(node->val);
}

std::vector<int> postorderTraversal(TreeNode *root) {
  if (!root) return {};
  std::vector<int> ans;
  postorderTraversal_aux(root, ans);
  return ans;
}