//
// Created by lp on 2022/9/20.
//

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;

  do {
	if (fast==nullptr)return nullptr;
	fast = fast->next;
	if (fast==nullptr)return nullptr;
	fast = fast->next;
	slow = slow->next;
  } while (fast!=slow);

  fast = head;
  while (fast!=slow) {
	fast = fast->next;
	slow = slow->next;
  }

  return fast;
}