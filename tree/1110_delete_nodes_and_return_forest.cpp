//
// Created by lp on 2022/12/15.
//
#include "vector"
#include "unordered_set"
#include "memory"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 自顶向下
void delNodes_aux(TreeNode *node,
				  TreeNode *parent,
				  bool is_left,
				  std::vector<TreeNode *> &forest,
				  const std::unordered_set<int> &to_delete) {
  if (!node) return;
  if (to_delete.count(node->val)==0) {
	if (!parent) forest.push_back(node);
	delNodes_aux(node->left, node, true, forest, to_delete);
	delNodes_aux(node->right, node, false, forest, to_delete);
  } else {
	if (parent) is_left ? parent->left = nullptr : parent->right = nullptr;
	delNodes_aux(node->left, nullptr, true, forest, to_delete);
	delNodes_aux(node->right, nullptr, false, forest, to_delete);
	delete node;
	node = nullptr;
  }
}

std::vector<TreeNode *> delNodes(TreeNode *root, std::vector<int> &to_delete) {
  if (to_delete.size()==0) return {root};
  std::unordered_set<int> set_to_delete(to_delete.size());
  for (const int i : to_delete) {
	set_to_delete.insert(i);
  }

  std::vector<TreeNode *> forest;
  delNodes_aux(root, nullptr, true, forest, set_to_delete);
  return forest;
}

// 自底向上
TreeNode *delNodes_down2top_aux(TreeNode *root,
								std::vector<TreeNode *> &forest,
								const std::unordered_set<int> &to_delete) {
  if (!root) return nullptr;

  root->left = delNodes_down2top_aux(root->left, forest, to_delete);
  root->right = delNodes_down2top_aux(root->right, forest, to_delete);
  if (to_delete.count(root->val)) {
	if (root->left) forest.push_back(root->left);
	if (root->right) forest.push_back(root->right);
	delete root;
	root = nullptr;
  }
  return root;
}

std::vector<TreeNode *> delNodes_(TreeNode *root, std::vector<int> &to_delete) {
  if (to_delete.size()==0) return {root};
  std::unordered_set<int> set_to_delete(to_delete.begin(), to_delete.end());

  std::vector<TreeNode *> forest;
  root = delNodes_down2top_aux(root, forest, set_to_delete);
  if (root) forest.push_back(root);
  return forest;
}
