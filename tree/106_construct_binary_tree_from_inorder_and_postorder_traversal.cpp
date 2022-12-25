//
// Created by lp on 2022/12/21.
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

TreeNode *buildTree_aux(const std::vector<int> &inorder,
						int inorder_begin,
						int inorder_end,
						const std::vector<int> &postorder,
						int index) {
  if (inorder_begin >= inorder_end) return nullptr;

  TreeNode *node = new TreeNode(postorder[index]);
  int mid = inorder_begin;
  for (; mid < inorder_end; ++mid) {
	if (inorder[mid]==postorder[index]) break;
  }

  int left_index = index - (inorder_end - mid);
  node->right = buildTree_aux(inorder, mid + 1, inorder_end, postorder, index - 1);
  node->left = buildTree_aux(inorder, inorder_begin, mid, postorder, left_index);
  return node;
}

TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
  return buildTree_aux(inorder, 0, inorder.size(), postorder, postorder.size() - 1);
}

