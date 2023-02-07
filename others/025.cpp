//
// Created by lp on 2023/2/7.
//
#include "memory"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverse_k(ListNode *begin, ListNode *end) {
  if (begin==end || begin->next==end) return begin;
  ListNode *next = begin->next, *next_next = next->next;
  begin->next = nullptr;
  while (next_next!=end) {
	next->next = begin;
	begin = next;
	next = next_next;
	next_next = next->next;
  }
  next->next = begin;
  return next;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  if (!head) return nullptr;
  if (!head->next || k==1) return head;

  std::unique_ptr<ListNode> dummy(new ListNode());
  ListNode *begin = nullptr, *end = nullptr, *last = dummy.get();
  int i = 1;
  while (head) {
	begin = end = head;
	i = 1;
	while (end && i < k) {
	  end = end->next;
	  ++i;
	}
	if (!end) {
	  last->next = begin;
	  break;
	}
	head = end->next;
	last->next = reverse_k(begin, end->next);
	last = begin;
  }

  return dummy->next;
}