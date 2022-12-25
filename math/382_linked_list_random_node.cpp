//
// Created by lp on 2022/11/6.
//
#include "cmath"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  Solution(ListNode *head) {
	if (head) {
	  m_head = new ListNode(head->val);
	  head = head->next;
	}

	ListNode *cur = m_head;
	while (head) {
	  cur->next = new ListNode(head->val);
	  cur = cur->next;
	  head = head->next;
	}
  }

  int getRandom() {
	int val = 0, index = 1;
	ListNode *cur = m_head;
	while (cur) {
	  if (rand()%index==0) {
		val = cur->val;
	  }
	  cur = cur->next;
	  ++index;
	}

	return val;
  }

  ~Solution() {
	ListNode *next = nullptr;
	while (m_head) {
	  next = m_head->next;
	  delete m_head;
	  m_head = next;
	}
  }

 private:
  ListNode *m_head;
};
