//
// Created by lp on 2022/12/18.
//
#include "string"

struct TrieNode {
  TrieNode *child_node[26];
  bool is_value;
  TrieNode() : is_value(false) {
	for (int i = 0; i < 26; ++i) {
	  child_node[i] = nullptr;
	}
  }
};

class Trie {
 public:
  Trie() : root(new TrieNode) {}

  void insert(std::string word) {
	if (word.size()==0) return;
	TrieNode *node = root;
	int tmp;
	for (int i = 0; i < word.size(); ++i) {
	  tmp = word[i] - 'a';
	  if (!(node->child_node)[tmp]) {
		(node->child_node)[tmp] = new TrieNode;
	  }
	  node = (node->child_node)[tmp];
	}
	node->is_value = true;
  }

  bool search(std::string word) {
	int n = word.size();
	if (n==0) return true;

	TrieNode *node = root;
	for (int i = 0; i < n; ++i) {
	  if (!node) return false;
	  node = (node->child_node)[word[i] - 'a'];
	}
	return node ? node->is_value : false;
  }

  bool startsWith(std::string prefix) {
	int n = prefix.size();
	if (n==0) return true;
	TrieNode *node = root;
	for (int i = 0; i < n; ++i) {
	  if (!node) return false;
	  node = (node->child_node)[prefix[i] - 'a'];
	}
	return node;
  }

  ~Trie() {
	_delete_nodes(root);
  }

 private:
  void _delete_nodes(TrieNode *node) {
	if (!node) return;
	for (int i = 0; i < 26; ++i) {
	  _delete_nodes(node->child_node[i]);
	}
	delete node;
  }

 private:
  TrieNode *root;
};