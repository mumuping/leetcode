//
// Created by lp on 2022/12/19.
//
#include "cmath"
#include "algorithm"
#include "climits"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getMini(TreeNode *cur, TreeNode *&pre, int &min_val) {
  if (!cur) return;
  getMini(cur->left, pre, min_val);
  if (pre) {
	min_val = std::min(std::abs(pre->val - cur->val), min_val);
  }
  pre = cur;
  getMini(cur->right, pre, min_val);
}

int getMinimumDifference(TreeNode *root) {
  int min_val = INT_MAX;
  TreeNode* tmp= nullptr;
  getMini(root, tmp, min_val);
  return min_val;
}