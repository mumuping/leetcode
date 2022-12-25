//
// Created by lp on 2022/12/18.
//
#include "vector"
#include "climits"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode *root, TreeNode *subRoot) {
  if (!root && !subRoot) return true;
  if (!root || !subRoot || root->val!=subRoot->val) return false;
  return check(root->left, subRoot->left) && check(root->right, subRoot->right);
}

bool dfs(TreeNode *root, TreeNode *subRoot) {
  if (!root) return false;
  return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {
  return dfs(root, subRoot);
}

// 转化为字符串查找
void getElementOfTree(TreeNode *node, std::vector<int> &elements) {
  if (!node) return;
  elements.push_back(node->val);
  if (node->left) {
	getElementOfTree(node->left, elements);
  } else {
	elements.push_back(INT_MIN);
  }
  if (node->right) {
	getElementOfTree(node->right, elements);
  } else {
	elements.push_back(INT_MAX);
  }
}

void getNextNumbers(const std::vector<int> &nums, std::vector<int> &next) {
  int n = nums.size();
  int i = 0, j = 1;
  next[0] = 0;
  while (j < n) {
	if (i > 0 && nums[i]!=nums[j]) {
	  i = next[i - 1];
	}
	if (nums[i]==nums[j]) ++i;
	next[j++] = i;
  }
}

bool kmp(const std::vector<int> &root_elements, const std::vector<int> &sub_root_elements) {
  std::vector<int> next(sub_root_elements.size());
  getNextNumbers(sub_root_elements, next);

  int m = root_elements.size(), n = sub_root_elements.size();
  int i = 0, j = 0;
  while (i < m) {
	while (j > 0 && root_elements[i]!=sub_root_elements[j]) {
	  j = next[j - 1];
	}
	if (root_elements[i]==sub_root_elements[j]) ++j;
	if (j==n) return true;
	++i;
  }

  return false;
}

bool isSubtree_kmp(TreeNode *root, TreeNode *subRoot) {
  if (!subRoot || root==subRoot) return true;

  std::vector<int> root_elements, sub_root_elements;
  getElementOfTree(root, root_elements);
  getElementOfTree(subRoot, sub_root_elements);
  return kmp(root_elements, sub_root_elements);
}
