//
// Created by lp on 2022/12/20.
//
#include "vector"
#include "unordered_map"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* constructTree(std::vector<int>& preorder, std::vector<int>& postorder, int preLeft, int preRight,
						int postLeft, int postRight){
  if (preLeft>preRight){
	return nullptr;
  }
  TreeNode* root = new TreeNode(preorder[preLeft]);
  if (preLeft==preRight){
	return root;
  }
  int L=0;
  for (int i=postLeft; i<=postRight; i++){
	if (postorder[i]==preorder[preLeft+1]){
	  L = i - postLeft + 1;
	}
  }
  root->left = constructTree(preorder, postorder, preLeft+1, preLeft+L, postLeft, postLeft+L-1);
  root->right = constructTree(preorder, postorder,preLeft+L+1, preRight, postLeft+L, postRight-1);
  return root;
}

TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
  int n = preorder.size();
  return constructTree(preorder, postorder, 0, n-1, 0, n-1);
}
