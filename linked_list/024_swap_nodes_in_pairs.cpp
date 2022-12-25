//
// Created by lp on 2022/12/11.
//
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归版本
ListNode *swapPairs_R(ListNode *head) {
  if (!head || !head->next) return head;
  ListNode *next = head->next;
  head->next = swapPairs_R(next->next);
  next->next = head;
  return next;
}

ListNode *swapPairs(ListNode *head) {
  if (!head || !head->next) return head;

  ListNode *dummy = new ListNode;
  dummy->next = head;
  ListNode *tmp = dummy;
  ListNode *cur = head, *next;
  while (cur && cur->next) {
	tmp->next = cur->next;
	next = cur->next->next;
	cur->next->next = cur;
	cur->next = next;
	tmp = cur;
	cur = cur->next;
  }

  tmp = dummy->next;
  delete dummy;
  dummy = nullptr;

  return tmp;
}