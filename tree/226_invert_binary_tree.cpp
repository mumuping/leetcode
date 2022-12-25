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

TreeNode *invertTree(TreeNode *root) {
  if (!root) return nullptr;
  TreeNode *tmp = root->left;
  root->left = invertTree(root->right);
  root->right = invertTree(tmp);
  return root;
}