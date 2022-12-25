//
// Created by lp on 2022/12/18.
//
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves_aux(TreeNode *node, bool is_left) {
  if (!node) return 0;
  if (!node->left && !node->right) return is_left ? node->val : 0;
  return sumOfLeftLeaves_aux(node->left, true) + sumOfLeftLeaves_aux(node->right, false);
}

int sumOfLeftLeaves(TreeNode *root) {
  return sumOfLeftLeaves_aux(root, false);
}
