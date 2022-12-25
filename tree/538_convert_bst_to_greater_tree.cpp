//
// Created by lp on 2022/12/19.
//
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root, int val) {
  if (!root) return val;

  root->val += dfs(root->right, val);
  return dfs(root->left, root->val);
}

TreeNode *convertBST(TreeNode *root) {
  dfs(root, 0);
  return root;
}