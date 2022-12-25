//
// Created by lp on 2022/12/14.
//
#include "cmath"
#include "algorithm"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int isBalanced_aux(TreeNode *root) {
  if (!root) return 0;

  int left_height = isBalanced_aux(root->left);
  if (left_height==-1) return -1;
  int right_height = isBalanced_aux(root->right);
  if (right_height==-1) return -1;

  if (std::abs(left_height - right_height) <= 1)
	return 1 + std::max(left_height, right_height);
  else
	return -1;
}

bool isBalanced(TreeNode *root) {
  return isBalanced_aux(root)!=-1;
}