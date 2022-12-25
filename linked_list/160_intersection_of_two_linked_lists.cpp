//
// Created by lp on 2022/12/12.
//
#include "unordered_set"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode_set(ListNode *headA, ListNode *headB) {
  if (!headA || !headB) return nullptr;

  std::unordered_set<ListNode *> set;
  while (headA) {
	set.insert(headA);
	headA = headA->next;
  }
  while (headB) {
	if (set.count(headB)==1) return headB;
	headB = headB->next;
  }
  return nullptr;
}

ListNode *getIntersectionNode_pointers(ListNode *headA, ListNode *headB) {
  ListNode *list1 = headA, *list2 = headB;
  while (list1!=list2) {
	list1 = list1 ? list1->next : headB;
	list2 = list2 ? list2->next : headA;
  }
  return list1;
}