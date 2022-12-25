//
// Created by lp on 2022/12/17.
//

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recoverTree_aux(TreeNode *node,
					 TreeNode *&mistake1,
					 TreeNode *&mistake2,
					 TreeNode *&pre) {
  if (!node) return;
  recoverTree_aux(node->left, mistake1, mistake2, pre);
  if (pre && node->val < pre->val) {
	if (!mistake1) {
	  mistake1 = pre;
	  mistake2 = node;
	} else {
	  mistake2 = node;
	}
  }
  pre = node;
  recoverTree_aux(node->right, mistake1, mistake2, pre);
}

void recoverTree(TreeNode *root) {
  if (!root || (!root->left && !root->right)) return;
  TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *pre = nullptr;
  recoverTree_aux(root, mistake1, mistake2, pre);
  if (mistake1 && mistake2) {
	int val = mistake1->val;
	mistake1->val = mistake2->val;
	mistake2->val = val;
  }
  return;
}
