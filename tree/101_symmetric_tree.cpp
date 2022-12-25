//
// Created by lp on 2022/12/15.
//
#include "queue"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetric_aux(TreeNode *root1, TreeNode *root2) {
  if (!root1 && !root2) return true;
  if (!root1 || !root2 || root1->val!=root2->val) return false;

  return isSymmetric_aux(root1->left, root2->right) &&
	  isSymmetric_aux(root1->right, root2->left);
}

bool isSymmetric_r(TreeNode *root) {
  if (!root) return true;
  return isSymmetric_aux(root->left, root->right);
}

bool isSymmetric(TreeNode *root) {
  if (!root || (!root->left && !root->right)) return true;
  std::queue<TreeNode *> q;
  q.push(root->left);
  q.push(root->right);

  TreeNode *left = nullptr, *right = nullptr;
  while (!q.empty()) {
	left = q.front();
	q.pop();
	right = q.front();
	q.pop();
	if (left && right) {
	  if (left->val!=right->val) return false;
	  q.push(left->left);
	  q.push(right->right);
	  q.push(left->right);
	  q.push(right->left);
	}
	if ((left && !right) || (!left && right)) return false;
  }

  return true;
}
