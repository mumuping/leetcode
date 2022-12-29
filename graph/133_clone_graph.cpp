//
// Created by lp on 2022/12/29.
//
#include "vector"
#include "unordered_map"

// Definition for a Node.
class Node {
 public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
	val = 0;
	neighbors = std::vector<Node *>();
  }
  Node(int _val) {
	val = _val;
	neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
	val = _val;
	neighbors = _neighbors;
  }
};

Node *dfs_clone(Node *cur, std::unordered_map<int, Node *> &nodes) {
  auto it = nodes.find(cur->val);
  if (it!=nodes.end()) return it->second;
  Node *copy = new Node(cur->val);
  nodes.insert(std::make_pair(cur->val, copy));
  for (auto next : cur->neighbors) {
	copy->neighbors.push_back(dfs_clone(next, nodes));
  }
  return copy;
}

Node *cloneGraph(Node *node) {
  if (!node) return nullptr;
  std::unordered_map<int, Node *> nodes;
  return dfs_clone(node, nodes);
}