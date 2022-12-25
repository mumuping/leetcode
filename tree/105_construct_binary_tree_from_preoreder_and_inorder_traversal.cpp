//
// Created by lp on 2022/12/16.
//
#include "vector"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline int find(const std::vector<int> &order, int begin, int end, int target) {
  while (begin!=end) {
	if (order[begin]==target) return begin;
	++begin;
  }
  return begin;
}

TreeNode *buildTree_aux(const std::vector<int> &preorder,
						int i,
						const std::vector<int> &inorder,
						int begin,
						int end) {
  if (begin >= end) return nullptr;

  int val = preorder[i];
  int mid = find(inorder, begin, end, val);
  int num_of_left_nodes = mid - begin;
  TreeNode *node = new TreeNode(val);
  node->left = buildTree_aux(preorder, i + 1, inorder, begin, begin + num_of_left_nodes);
  node->right = buildTree_aux(preorder, i + num_of_left_nodes + 1, inorder, mid + 1, end);
  return node;
}

TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
  if (preorder.size()==0 || inorder.size()==0) return nullptr;
  return buildTree_aux(preorder, 0, inorder, 0, inorder.size());
}
