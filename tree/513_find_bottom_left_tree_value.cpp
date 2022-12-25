//
// Created by lp on 2022/12/19.
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

// 从左往右层次遍历
int findBottomLeftValue(TreeNode *root) {
  int left_value = 0;
  std::queue<TreeNode *> q;
  q.push(root);

  int size = 0;
  TreeNode *tmp = nullptr;
  while (!q.empty()) {
	size = q.size();
	tmp = q.front();
	if (tmp->left) q.push(tmp->left);
	if (tmp->right) q.push(tmp->right);
	q.pop();
	left_value = tmp->val;

	for (int i = 0; i < size - 1; ++i) {
	  tmp = q.front();
	  if (tmp->left) q.push(tmp->left);
	  if (tmp->right) q.push(tmp->right);
	  q.pop();
	}
  }

  return left_value;
}

// 从右往左层次遍历
int findBottomLeftValue_right2left(TreeNode *root) {
  std::queue<TreeNode *> q;
  q.push(root);
  int val;
  TreeNode *tmp = nullptr;
  while (!q.empty()) {
	tmp = q.front();
	q.pop();
	if (tmp->right) q.push(tmp->right);
	if (tmp->left) q.push(tmp->left);
	val = tmp->val;
  }
  return val;
}