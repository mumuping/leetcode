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

// 归并排序

// 寻找中间节点
ListNode *findMiddle(ListNode *begin, ListNode *end) {
  ListNode *first = begin, *second = begin;
  while (second->next!=end && second->next->next!=end) {
	first = first->next;
	second = second->next->next;
  }

  return first;
}

// 合并两个链表
ListNode *mergeLists(ListNode *list1_begin, ListNode *list1_end, ListNode *list2_begin, ListNode *list2_end) {
  if (list1_begin==list1_end) return list2_begin;
  if (list2_begin==list2_end) return list1_begin;

  ListNode *dummy = new ListNode;
  ListNode *head = dummy;
  while (list1_begin!=list1_end && list2_begin!=list2_end) {
	if (list1_begin->val < list2_begin->val) {
	  head->next = list1_begin;
	  list1_begin = list1_begin->next;
	} else {
	  head->next = list2_begin;
	  list2_begin = list2_begin->next;
	}
	head = head->next;
  }

  if (list1_begin!=list1_end) head->next = list1_begin;
  if (list2_begin!=list2_end) head->next = list2_begin;
  head = dummy->next;
  delete dummy;
  dummy = nullptr;
  return head;
}

ListNode *sort_list(ListNode *begin, ListNode *end) {
  if (begin==end) return nullptr;
  if (begin->next==end) {
	begin->next = nullptr;
	return begin;
  }

  ListNode *middle = findMiddle(begin, end);
  ListNode *right = middle->next;
  ListNode *left = sort_list(begin, right);
  right = sort_list(right, end);

  return mergeLists(left, nullptr, right, nullptr);
}

ListNode *sortList(ListNode *head) {
  if (!head) return nullptr;
  if (!head->next) return head;

  return sort_list(head, nullptr);
}