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

ListNode *reverseList(ListNode *head) {
  if (!head || !head->next) return head;

  ListNode *pre = nullptr, *next = nullptr;
  while (head) {
	next = head->next;
	head->next = pre;
	pre = head;
	head = next;
  }

  return pre;
}

ListNode *reverseList(ListNode *head, ListNode *pre) {
  if (!head) return pre;
  ListNode *next = head->next;
  head->next = pre;
  return reverseList(next, head);
}