//
// Created by lp on 2022/12/16.
//
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *flatten_aux(TreeNode *node) {
  if (!node || (!node->left && !node->right)) return node;

  TreeNode *left_last = flatten_aux(node->left);
  TreeNode *right_last = flatten_aux(node->right);
  if (!left_last) return right_last;
  left_last->right = node->right;
  node->right = node->left;
  node->left = nullptr;
  return right_last ? right_last : left_last;
}

void flatten(TreeNode *root) {
  if (!root || (!root->left && !root->right)) return;

  flatten_aux(root);
}