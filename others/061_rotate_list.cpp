//
// Created by lp on 2023/2/27.
//
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k) {
  if (k==0 || !head) return head;

  int length = 1;
  ListNode *tmp = head;
  while (tmp->next) {
	++length;
	tmp = tmp->next;
  }

  k %= length;
  if (k==0) return head;
  k = length - 1 - k;
  tmp->next = head;
  tmp = head;
  while (k > 0) {
	tmp = tmp->next;
	--k;
  }

  head = tmp->next;
  tmp->next = nullptr;
  return head;
}