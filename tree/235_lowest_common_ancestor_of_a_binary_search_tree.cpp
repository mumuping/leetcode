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

TreeNode *lowestCommonAncestor_aux(TreeNode *root, int p_val, int q_val) {
  if (!root) return nullptr;
  if ((p_val <= root->val && root->val <= q_val) || (q_val <= root->val && root->val <= p_val)) return root;
  if (p_val < root->val && q_val < root->val) return lowestCommonAncestor_aux(root->left, p_val, q_val);
  return lowestCommonAncestor_aux(root->right, p_val, q_val);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  return lowestCommonAncestor_aux(root, p->val, q->val);
}