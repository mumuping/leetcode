//
// Created by lp on 2022/12/14.
//
#include "algorithm"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int diameterOfBinaryTree_aux(TreeNode *root, int &diameter) {
  if (!root) return 0;

  int left = diameterOfBinaryTree_aux(root->left, diameter);
  int right = diameterOfBinaryTree_aux(root->right, diameter);
  diameter = std::max(diameter, left + right);
  return std::max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
  int diameter = -1;
  diameterOfBinaryTree_aux(root, diameter);
  return diameter;
}