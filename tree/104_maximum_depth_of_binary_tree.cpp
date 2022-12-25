//
// Created by lp on 2022/12/14.
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

int maxDepth_r(TreeNode *root) {
  if (!root) return 0;
  return std::max(maxDepth_r(root->left), maxDepth_r(root->right)) + 1;
}

int maxDepth(TreeNode *root) {
  if (!root) return 0;

  std::queue<TreeNode *> q;
  q.push(root);

  int depth = 0, num_of_node;
  TreeNode *node = nullptr;
  while (!q.empty()) {
	num_of_node = q.size();
	++depth;
	for (int i = 0; i < num_of_node; ++i) {
	  node = q.front();
	  q.pop();
	  if (node->left) q.push(node->left);
	  if (node->right) q.push(node->right);
	}
  }

  return depth;
}

