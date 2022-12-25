//
// Created by lp on 2022/12/23.
//

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *inorder(ListNode *&head, int l, int r) {
  if (l > r) return nullptr;
  int mid = l + (r - l)/2;
  TreeNode *node = new TreeNode();
  node->left = inorder(head, l, mid - 1);
  node->val = head->val;
  head = head->next;
  node->right = inorder(head, mid + 1, r);
  return node;
}

TreeNode *sortedListToBST_inorder(ListNode *head) {
  if (!head) return nullptr;
  if (!head->next) return new TreeNode(head->val);
  ListNode *tmp = head;
  int length = 0;
  while (tmp) {
	++length;
	tmp = tmp->next;
  }
  return inorder(head, 0, length - 1);
}

inline ListNode *getMid(ListNode *begin, ListNode *end) {
  ListNode *tmp = begin;
  while (tmp->next!=end && tmp->next->next!=end) {
	begin = begin->next;
	tmp = tmp->next->next;
  }
  return begin;
}

TreeNode *buildBST(ListNode *begin, ListNode *end) {
  if (begin==end) return nullptr;
  ListNode *mid = getMid(begin, end);
  TreeNode *node = new TreeNode(mid->val);
  node->left = buildBST(begin, mid);
  node->right = buildBST(mid->next, end);
  return node;
}

TreeNode *sortedListToBST(ListNode *head) {
  if (!head) return nullptr;
  if (!head->next) return new TreeNode(head->val);
  return buildBST(head, nullptr);
}