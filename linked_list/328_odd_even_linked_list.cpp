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

ListNode *oddEvenList(ListNode *head) {
  if (!head || !head->next || !head->next->next) return head;

  ListNode *odd_tail = head, *even_head = head->next, *even_tail = even_head;
  ListNode *cur = even_tail->next;
  while (cur) {
	even_tail->next = cur->next;
	cur->next = even_head;
	odd_tail->next = cur;
	odd_tail = cur;
	even_tail = even_tail->next;
	if (!even_tail) return head;
	cur = even_tail->next;
  }

  return head;
}

// 递归版本
void recursive(ListNode *head, ListNode *&odd, ListNode *&even) {
  if (!head) {
	odd = even = nullptr;
  } else if (!head->next) {
	odd = head;
	even = nullptr;
  } else {
	ListNode *tmp_odd, *tmp_even;
	recursive(head->next->next, tmp_odd, tmp_even);
	head->next->next = tmp_even;
	even=head->next;
	head->next = tmp_odd;
	odd = head;
  }
}

ListNode *oddEvenList_r(ListNode *head) {
  if (!head || !head->next || !head->next->next) return head;
  ListNode *odd, *even;
  recursive(head, odd, even);

  while (odd->next) {
	odd = odd->next;
  }
  odd->next=even;
  return head;
}