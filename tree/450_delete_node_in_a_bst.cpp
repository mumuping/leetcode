//
// Created by lp on 2022/12/24.
//
#include "memory"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *deleteNode(TreeNode *root, int key) {
  if (!root) return nullptr;

  std::shared_ptr<TreeNode> dummy(new TreeNode);
  dummy->left = root;
  TreeNode *cur = root, *pre_cur = dummy.get();
  while (cur->val!=key) {
	pre_cur = cur;
	if (cur->val < key) cur = cur->right;
	else cur = cur->left;
	if (!cur) return dummy->left;
  }

  TreeNode *pre_cur_next = nullptr;
  if (!cur->left && !cur->right) {
	pre_cur_next = nullptr;
  } else if (!cur->left) {
	pre_cur_next = cur->right;
  } else if (!cur->right) {
	pre_cur_next = cur->left;
  } else {
	TreeNode *pre_right = cur, *right = cur->right;
	if (!right->left) {
	  right->left = cur->left;
	} else {
	  while (right->left) {
		pre_right = right;
		right = right->left;
	  }
	  pre_right->left = right->right;
	  right->right = cur->right;
	  right->left = cur->left;
	}
	pre_cur_next = right;
  }

  if (pre_cur->left==cur) {
	pre_cur->left = pre_cur_next;
  } else {
	pre_cur->right = pre_cur_next;
  }

  delete cur;
  cur = nullptr;
  return dummy->left;
}