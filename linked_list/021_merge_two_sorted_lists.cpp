//
// Created by lp on 2022/12/11.
//
#include "memory"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (!list2) return list1;
  if (!list1) return list2;

  ListNode *dummy = new ListNode();
  ListNode *head = dummy;
  while (list1 && list2) {
	if (list1->val < list2->val) {
	  head->next = list1;
	  list1 = list1->next;
	} else {
	  head->next = list2;
	  list2 = list2->next;
	}
	head = head->next;
  }
  if (list1) head->next = list1;
  if (list2) head->next = list2;

  head = dummy->next;
  delete dummy;
  dummy= nullptr;
  return head;
}

ListNode *mergeTwoLists_R(ListNode *list1, ListNode *list2) {
  if (!list2) return list1;
  if (!list1) return list2;

  if (list1->val < list2->val) {
	list1->next = mergeTwoLists_R(list1->next, list2);
	return list1;
  } else {
	list2->next = mergeTwoLists_R(list1, list2->next);
	return list2;
  }
}