//
// Created by lp on 2022/12/14.
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

// 前缀和
std::unordered_map<long long, int> prefix;
int dfs(TreeNode *root, int targetSum, long long curr) {
  if (!root) return 0;

  int count = 0;
  curr += root->val;
  if (prefix.count(curr - targetSum)) {
	count = prefix[curr - targetSum];
  }

  ++prefix[curr];
  count += dfs(root->left, targetSum, curr);
  count += dfs(root->right, targetSum, curr);
  --prefix[curr];
  return count;
}

int pathSum_prefix(TreeNode* root, int targetSum) {
  prefix[0] = 1;
  return dfs(root, 0, targetSum);
}

// 递归遍历
int pathSum_aux(TreeNode *root, long sum) {
  if (!root) return 0;
  int count = root->val==sum ? 1 : 0;
  count += pathSum_aux(root->left, sum - root->val);
  count += pathSum_aux(root->right, sum - root->val);
  return count;
}

int pathSum(TreeNode *root, int targetSum) {
  return root ? pathSum_aux(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum) : 0;
}