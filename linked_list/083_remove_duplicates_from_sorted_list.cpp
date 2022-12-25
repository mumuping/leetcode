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

ListNode *deleteDuplicates(ListNode *head) {
  if (!head || !head->next) return head;

  ListNode *cur = head, *delete_node = nullptr;
  while (cur->next) {
	if (cur->val==cur->next->val) {
	  delete_node = cur->next;
	  cur->next = cur->next->next;
	  delete delete_node;
	  delete_node = nullptr;
	} else {
	  cur = cur->next;
	}
  }

  return head;
}