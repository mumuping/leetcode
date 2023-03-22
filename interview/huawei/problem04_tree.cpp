//
// Created by 18315 on 2023/3/20.
//
// https://www.bilibili.com/video/BV1rZ4y1t7bB/?spm_id_from=333.788&vd_source=cae965f23b6cb71143bed6af4be19e37
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>

struct node {
  int data;
  std::shared_ptr<node> left;
  std::shared_ptr<node> right;
  node() : data(0), left(), right() {}
  explicit node(int d) : data(d), left(), right() {}
  node(int d, std::shared_ptr<node> &l, std::shared_ptr<node> &r) : data(d),
                                                                    left(l), right(r) {}
};

std::shared_ptr<node> create_tree(const std::vector<int> &array) {
  if (array.empty()) return nullptr;
  int n = array.size();
  std::vector<std::shared_ptr<node>> nodes(n);
  for (int i = 0; i < n; ++i) {
    if (array[i] != 0) {
      nodes[i] = std::make_shared<node>(array[i]);
    }
  }
  for (int i = 0; i < n / 2 - 1; ++i) {
    if (!nodes[i]) continue;
    nodes[i]->left = nodes[2 * i + 1];
    nodes[i]->right = nodes[2 * i + 2];
  }
  int last = n / 2 - 1;
  if (last * 2 + 1 < n) {
    nodes[last]->left = nodes[last * 2 + 1];
  }
  if (last * 2 + 2 < n) {
    nodes[last]->right = nodes[last * 2 + 2];
  }
  return nodes[0];
}

void find_subroot_pre(const std::string &s, const std::shared_ptr<node> &root,
                      std::shared_ptr<node> &res, bool &left) {
  if (s.empty() || !root) return;
  std::shared_ptr<node> dummy = std::make_shared<node>();
  dummy->left = root;
  left = true;
  std::shared_ptr<node> cur = dummy;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '/') continue;
    int value = s[i] - '0';
    if (cur->left && cur->left->data == value) {
      res = cur;
      left = true;
      cur = cur->left;
    } else if (cur->right && cur->right->data == value) {
      res = cur;
      left = false;
      cur = cur->right;
    } else {
      break;
    }
  }
}

void replace_subroot(std::shared_ptr<node> &pre_of_replaced,
                     bool left,
                     const std::shared_ptr<node> &new_root) {
  if (!pre_of_replaced) return;
  if (left) {
    pre_of_replaced->left = new_root;
  } else {
    pre_of_replaced->right = new_root;
  }
}

std::shared_ptr<node> solution() {
  // get the value of the tree nodes.
  std::vector<int> tree_nodes;
  std::string line;
  std::getline(std::cin, line);
  std::stringstream s1(line);
  int num;
  while (s1 >> num) {
    tree_nodes.emplace_back(num);
  }

  // get the subroot node.
  std::string subtree;
  std::getline(std::cin, subtree);

  // get the value of the subtree nodes.
  std::vector<int> subtree_nodes;
  line.clear();
  std::getline(std::cin, line);
  std::stringstream s2(line);
  while (s2 >> num) {
    subtree_nodes.emplace_back(num);
  }

  std::shared_ptr<node> tree_root = create_tree(tree_nodes);
  std::shared_ptr<node> subtree_root = create_tree(subtree_nodes);
  std::shared_ptr<node> pre;
  bool is_left;
  find_subroot_pre(subtree, tree_root, pre, is_left);
  if (pre->data == 0) {
    tree_root = subtree_root;
  } else {
    replace_subroot(pre, is_left, subtree_root);
  }

  return tree_root;
}