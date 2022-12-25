//
// Created by lp on 2022/12/23.
//
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void increasingBST_aux(TreeNode *node, TreeNode *&pre) {
  if (!node) return;
  increasingBST_aux(node->left, pre);
  pre->right = node;
  pre = node;
  node->left = nullptr;
  increasingBST_aux(node->right, pre);
}

TreeNode *increasingBST(TreeNode *root) {
  TreeNode *dummy = new TreeNode;
  TreeNode *tmp = dummy;
  increasingBST_aux(root, tmp);
  tmp = dummy->right;
  delete dummy;
  dummy = nullptr;
  return tmp;
}