//
// Created by lp on 2022/12/23.
//
#include "stack"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool dfs(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *&ancestor) {
  if (!root) return false;
  bool l = dfs(root->left, p, q, ancestor);
  if (ancestor) return true;
  bool r = dfs(root->right, p, q, ancestor);
  if ((l && r) || ((root->val==p->val || root->val==q->val) && (l || r))) {
	ancestor = root;
	return true;
  }
  return l || r || (root->val==q->val) || (root->val==p->val);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  TreeNode *ancestor = nullptr;
  dfs(root, p, q, ancestor);
  return ancestor;
}