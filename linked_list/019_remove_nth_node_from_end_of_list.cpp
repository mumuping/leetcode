//
// Created by lp on 2022/12/13.
//
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (!head) return nullptr;

  ListNode *dummy = new ListNode(0, head);
  ListNode *first = dummy, *second = dummy;
  while (n >= 0) {
	second = second->next;
	--n;
  }

  while (second) {
	second = second->next;
	first = first->next;
  }
  ListNode *delete_node = first->next;
  first->next = first->next->next;
  delete delete_node;

  delete_node = dummy;
  ListNode *res = dummy->next;
  delete delete_node;
  delete_node = nullptr;

  return res;
}