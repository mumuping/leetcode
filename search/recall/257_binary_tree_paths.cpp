//
// Created by lp on 2022/10/11.
//
#include "vector"
#include "string"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
  TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
};

void recall(std::vector<std::string> &res, TreeNode *node, std::string &path) {
  if (node) {
	// 如果当前节点存在，则把节点值加入进去
	std::string tmp = std::to_string(node->val);
	path += tmp;

	// 如果该节点是叶节点，则把该路径加入到结果集中
	if (!node->left && !node->right) {
	  res.push_back(path);
	}

	// 如果该节点不是叶节点，则访问子节点
	path += "->";
	if (node->left) recall(res, node->left, path);
	if (node->right) recall(res, node->right, path);

	// 该节点访问结束，清除状态
	path.erase(path.end() - 2 - tmp.size(), path.end());
  }
}

// 回溯
std::vector<std::string> binaryTreePaths(TreeNode *root) {
  std::vector<std::string> res;
  std::string path;
  recall(res, root, path);

  return res;
}

// 利用 dfs，注意这里没有使用引用，因此不用在遍历完一个节点后清除状态
void dfs(TreeNode *node, std::vector<std::string> &ans, std::string path) {
  if (node) {
	// 如果 node 节点存在，则把 node 节点加入到 path 中
	path += std::to_string(node->val);
	// 如果 node 无左右子节点，则把 path 加入到 ans 中
	if (!node->left && !node->right) {
	  ans.push_back(path);
	  return;
	}
	path += "->";
	if (node->left) dfs(node->left, ans, path);
	if (node->right) dfs(node->right, ans, path);
  }
}